#!/usr/bin/env python3
"""
Local Judge for Competitive Programming (Codeforces / CSES)
Compiles and runs C++ solutions against sample test cases in one command.
"""

import sys
import os
import subprocess
import time
import argparse
import tempfile
import difflib
import re
from pathlib import Path

# Ensure UTF-8 output encoding on Windows consoles
if sys.platform == "win32":
    try:
        sys.stdout.reconfigure(encoding='utf-8', errors='replace')
        sys.stderr.reconfigure(encoding='utf-8', errors='replace')
    except Exception:
        pass
    os.system('')  # Enable ANSI escape sequences on Windows 10/11

class Colors:
    GREEN = '\033[92m'
    RED = '\033[91m'
    YELLOW = '\033[93m'
    BLUE = '\033[94m'
    CYAN = '\033[96m'
    BOLD = '\033[1m'
    DIM = '\033[2m'
    RESET = '\033[0m'

def colorize(text, color):
    return f"{color}{text}{Colors.RESET}"

def find_compiler():
    """Find the best available C++ compiler."""
    preferred_paths = [
        r"C:\msys64\ucrt64\bin\g++.exe",
        r"C:\msys64\mingw64\bin\g++.exe",
        "g++"
    ]
    for compiler in preferred_paths:
        try:
            res = subprocess.run([compiler, "--version"], stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
            if res.returncode == 0:
                return compiler
        except Exception:
            continue
    return "g++"

def compile_source(source_path: Path, exe_path: Path, compiler: str):
    """Compile C++ source code with modern CP flags."""
    compile_cmd = [
        compiler,
        "-O2",
        "-std=c++17",
        "-Wall",
        "-Wextra",
        "-Wshadow",
        "-DLOCAL",
        str(source_path),
        "-o",
        str(exe_path)
    ]
    start = time.perf_counter()
    res = subprocess.run(compile_cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    compile_time = (time.perf_counter() - start) * 1000

    if res.returncode != 0:
        print(colorize("\n[COMPILATION ERROR]", Colors.RED + Colors.BOLD))
        print(colorize("-" * 65, Colors.RED))
        print(res.stderr.strip())
        print(colorize("-" * 65, Colors.RED))
        return False, compile_time

    return True, compile_time

def normalize_output(text: str) -> list[str]:
    """Normalize output for fair comparison: strip \\r, strip trailing spaces, remove trailing empty lines."""
    lines = [line.rstrip() for line in text.replace('\r\n', '\n').split('\n')]
    while lines and lines[-1] == '':
        lines.pop()
    return lines

def parse_delimiter_file(file_path: Path):
    """Parse sample tests file with delimiters like === INPUT === and === OUTPUT ===."""
    try:
        content = file_path.read_text(encoding='utf-8')
    except Exception:
        content = file_path.read_text(encoding='latin-1', errors='ignore')

    pattern = re.compile(
        r'(?:={3,}|-{3,})\s*INPUT\s*(?:={3,}|-{3,})(.*?)(?:={3,}|-{3,})\s*(?:OUTPUT|EXPECTED|ANS)\s*(?:={3,}|-{3,})(.*?)(?=(?:={3,}|-{3,})\s*INPUT|\Z)',
        re.DOTALL | re.IGNORECASE
    )
    matches = pattern.findall(content)

    tests = []
    if matches:
        for idx, (inp, out) in enumerate(matches, 1):
            tests.append({
                'name': f"Sample {idx}",
                'input': inp.strip(),
                'expected': out.strip()
            })
    return tests

def read_text_safe(path: Path) -> str:
    try:
        return path.read_text(encoding='utf-8').strip()
    except Exception:
        return path.read_text(encoding='latin-1', errors='ignore').strip()

def find_test_cases(source_path: Path):
    """Discover all test cases associated with the source file."""
    src_dir = source_path.parent
    stem = source_path.stem
    tests = []

    # 1. Multi-test single file format: <stem>.tests, <stem>_tests.txt, tests.txt, samples.txt
    for test_file_name in [f"{stem}.tests", f"{stem}_tests.txt", "tests.txt", "samples.txt", "sample.txt"]:
        p = src_dir / test_file_name
        if p.is_file():
            parsed = parse_delimiter_file(p)
            if parsed:
                return parsed

    # 2. Numbered test case pairs: in1.txt / out1.txt, sample1.in / sample1.out, 118A_in1.txt / 118A_out1.txt
    num_pattern = re.compile(r'^(?:' + re.escape(stem) + r'_)?(?:in|sample|test)_?(\d+)\.(?:txt|in)$', re.IGNORECASE)
    all_files = list(src_dir.glob("*"))

    numbered_map = {}
    for f in all_files:
        match = num_pattern.match(f.name)
        if match:
            idx = int(match.group(1))
            numbered_map[idx] = f

    if numbered_map:
        for idx in sorted(numbered_map.keys()):
            in_file = numbered_map[idx]
            # Look for corresponding expected file
            exp_candidates = [
                src_dir / f"{stem}_out{idx}.txt",
                src_dir / f"{stem}_ans{idx}.txt",
                src_dir / f"{stem}_expected{idx}.txt",
                src_dir / f"out{idx}.txt",
                src_dir / f"ans{idx}.txt",
                src_dir / f"expected{idx}.txt",
                src_dir / f"sample{idx}.out",
                src_dir / f"sample{idx}.ans",
                src_dir / f"test{idx}.out",
                src_dir / f"test{idx}.ans",
            ]
            exp_file = next((c for c in exp_candidates if c.is_file()), None)
            inp_text = read_text_safe(in_file)
            exp_text = read_text_safe(exp_file) if exp_file else None

            tests.append({
                'name': in_file.name,
                'input': inp_text,
                'expected': exp_text
            })
        return tests

    # 3. Problem-specific pair: <stem>_in.txt and <stem>_out.txt / <stem>_expected.txt
    stem_in = src_dir / f"{stem}_in.txt"
    if stem_in.is_file() and stem_in.stat().st_size > 0:
        exp_candidates = [
            src_dir / f"{stem}_out.txt",
            src_dir / f"{stem}_ans.txt",
            src_dir / f"{stem}_expected.txt",
        ]
        exp_file = next((c for c in exp_candidates if c.is_file()), None)
        tests.append({
            'name': stem_in.name,
            'input': read_text_safe(stem_in),
            'expected': read_text_safe(exp_file) if exp_file else None
        })
        return tests

    # 4. Standard input.txt & expected.txt / output.txt in source directory
    for search_dir in [src_dir, Path.cwd()]:
        in_file = search_dir / "input.txt"
        if in_file.is_file() and in_file.stat().st_size > 0:
            exp_candidates = [
                search_dir / "expected.txt",
                search_dir / "output.txt",
                search_dir / "ans.txt"
            ]
            exp_file = next((c for c in exp_candidates if c.is_file() and c.stat().st_size > 0), None)
            tests.append({
                'name': f"input.txt",
                'input': read_text_safe(in_file),
                'expected': read_text_safe(exp_file) if exp_file else None
            })
            return tests

    return tests

def run_test(exe_path: Path, input_text: str, time_limit: float):
    """Execute compiled binary with input and measure execution stats."""
    start = time.perf_counter()
    try:
        proc = subprocess.run(
            [str(exe_path)],
            input=input_text,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True,
            timeout=time_limit
        )
        elapsed = (time.perf_counter() - start) * 1000
        return proc.returncode, proc.stdout, proc.stderr, elapsed, False
    except subprocess.TimeoutExpired as e:
        elapsed = (time.perf_counter() - start) * 1000
        stdout = e.stdout if e.stdout else ""
        stderr = e.stderr if e.stderr else ""
        return -1, stdout, stderr, elapsed, True

def print_diff(expected: str, actual: str):
    """Display clean side-by-side or line comparison."""
    exp_lines = normalize_output(expected)
    act_lines = normalize_output(actual)

    print(colorize("  --- Expected Output ---", Colors.CYAN))
    for line in exp_lines:
        print(f"  {colorize(line, Colors.GREEN)}")
    print(colorize("  --- Actual Output ---", Colors.CYAN))
    for line in act_lines:
        print(f"  {colorize(line, Colors.RED)}")

    print(colorize("  --- Unified Diff ---", Colors.YELLOW))
    diff = list(difflib.unified_diff(exp_lines, act_lines, fromfile="Expected", tofile="Actual", lineterm=""))
    for d in diff:
        if d.startswith('+') and not d.startswith('+++'):
            print(f"  {colorize(d, Colors.RED)}")
        elif d.startswith('-') and not d.startswith('---'):
            print(f"  {colorize(d, Colors.GREEN)}")
        else:
            print(f"  {colorize(d, Colors.DIM)}")

def main():
    parser = argparse.ArgumentParser(description="Local Judge for Competitive Programming")
    parser.add_argument("source", nargs="?", default=None, help="Path to .cpp source file")
    parser.add_argument("-t", "--time-limit", type=float, default=2.0, help="Time limit per test in seconds (default: 2.0s)")
    parser.add_argument("-i", "--interactive", action="store_true", help="Run interactively in console")
    parser.add_argument("-a", "--add", action="store_true", help="Add or edit sample test case")
    args = parser.parse_args()

    # Locate source file
    if args.source:
        source_path = Path(args.source).resolve()
    else:
        cpp_files = list(Path.cwd().glob("*.cpp"))
        if len(cpp_files) == 1:
            source_path = cpp_files[0].resolve()
        else:
            print(colorize("Usage: python judge.py <file.cpp> [options]", Colors.YELLOW))
            if cpp_files:
                print("Available .cpp files in current directory:")
                for f in cpp_files:
                    print(f"  - {f.name}")
            sys.exit(1)

    if not source_path.is_file():
        print(colorize(f"Error: Source file '{source_path}' does not exist.", Colors.RED))
        sys.exit(1)

    compiler = find_compiler()
    print(colorize("=" * 65, Colors.BLUE))
    print(f" {colorize('[LOCAL JUDGE]', Colors.BOLD + Colors.CYAN)}  |  {colorize(source_path.name, Colors.BOLD)}  |  CP Practice")
    print(f" Compiler: {colorize(Path(compiler).name, Colors.DIM)} ({compiler})")
    try:
        rel_path = source_path.relative_to(Path.cwd())
    except ValueError:
        rel_path = source_path
    print(f" Target:   {colorize(str(rel_path), Colors.CYAN)}")
    print(colorize("=" * 65, Colors.BLUE))

    # Handle --add flag
    if args.add:
        src_dir = source_path.parent
        inp_file = src_dir / "input.txt"
        exp_file = src_dir / "expected.txt"
        print(colorize("\n[Add Sample Test Case]", Colors.CYAN + Colors.BOLD))
        print("Enter sample input (Press Enter, then Ctrl+Z / Ctrl+D to submit):")
        inp_lines = sys.stdin.read()
        inp_file.write_text(inp_lines.strip() + "\n", encoding='utf-8')
        print(colorize(f"Saved input to {inp_file.name}", Colors.GREEN))
        sys.exit(0)

    # Temporary binary path
    temp_dir = tempfile.gettempdir()
    exe_name = f"judge_{source_path.stem}_{os.getpid()}.exe"
    exe_path = Path(temp_dir) / exe_name

    # Step 1: Compile
    print(f"[*] Compiling {source_path.name} with -O2 -std=c++17...", end="", flush=True)
    compiled, comp_time = compile_source(source_path, exe_path, compiler)
    if not compiled:
        sys.exit(1)
    print(f" {colorize('DONE', Colors.GREEN)} ({comp_time:.1f} ms)")

    # Step 2: Interactive mode
    if args.interactive:
        print(colorize("\n[Interactive Mode - Direct Console Input/Output]", Colors.CYAN + Colors.BOLD))
        print(colorize("-" * 65, Colors.DIM))
        try:
            subprocess.run([str(exe_path)])
        finally:
            if exe_path.exists():
                try:
                    exe_path.unlink()
                except Exception:
                    pass
        print(colorize("\n" + "-" * 65, Colors.DIM))
        return

    # Step 3: Find test cases
    tests = find_test_cases(source_path)

    if not tests:
        src_dir = source_path.parent
        inp_file = src_dir / "input.txt"
        exp_file = src_dir / "expected.txt"
        if not inp_file.exists():
            inp_file.write_text("", encoding='utf-8')
        if not exp_file.exists():
            exp_file.write_text("", encoding='utf-8')

        print(colorize(f"\n[INFO] No sample test cases found for {source_path.name}.", Colors.YELLOW))
        print(f"Sample test files ready in {colorize(str(src_dir), Colors.CYAN)}:")
        print(f"  * {colorize('input.txt', Colors.BOLD)}    <- paste sample input here")
        print(f"  * {colorize('expected.txt', Colors.BOLD)} <- paste sample output here")
        print(f"\nTip: Paste tests into input.txt / expected.txt and re-run,")
        print(f"     or run with -i to test interactively directly in the terminal.")
        if exe_path.exists():
            try:
                exe_path.unlink()
            except Exception:
                pass
        return

    # Step 4: Run test cases
    print(f"[*] Found {colorize(str(len(tests)), Colors.BOLD)} test case(s). Running judge...\n")

    passed_count = 0
    total_tests = len(tests)

    try:
        for idx, test in enumerate(tests, 1):
            t_name = test.get('name', f'Test {idx}')
            inp = test.get('input', '')
            exp = test.get('expected', None)

            retcode, stdout, stderr, run_time, timed_out = run_test(exe_path, inp, args.time_limit)

            header = f"[{idx}/{total_tests}] {t_name}"

            if timed_out:
                print(f"{header:<30} {colorize('[TLE] TIME LIMIT EXCEEDED', Colors.YELLOW + Colors.BOLD)} [{run_time:.1f} ms > {args.time_limit*1000:.0f} ms]")
                continue

            if retcode != 0:
                print(f"{header:<30} {colorize(f'[RTE] RUNTIME ERROR (exit {retcode})', Colors.RED + Colors.BOLD)} [{run_time:.1f} ms]")
                if stderr.strip():
                    print(colorize(f"  Stderr: {stderr.strip()}", Colors.DIM))
                continue

            if exp is None:
                print(f"{header:<30} {colorize('[OK] EXECUTED', Colors.CYAN + Colors.BOLD)} [{run_time:.1f} ms]")
                print(colorize("  --- Output ---", Colors.DIM))
                for line in stdout.strip().split('\n'):
                    print(f"  {line}")
                print(colorize("  --------------", Colors.DIM))
                passed_count += 1
                continue

            # Compare actual vs expected
            norm_actual = normalize_output(stdout)
            norm_expected = normalize_output(exp)

            if norm_actual == norm_expected:
                print(f"{header:<30} {colorize('[AC] PASSED', Colors.GREEN + Colors.BOLD)} [{run_time:.1f} ms]")
                passed_count += 1
            else:
                print(f"{header:<30} {colorize('[WA] FAILED', Colors.RED + Colors.BOLD)} [{run_time:.1f} ms]")
                print_diff(exp, stdout)

        # Summary
        print(colorize("\n" + "=" * 65, Colors.BLUE))
        if total_tests > 0 and passed_count == total_tests:
            print(colorize(f"  [+] ALL {total_tests} SAMPLE TEST(S) PASSED! (100%)", Colors.GREEN + Colors.BOLD))
        else:
            print(colorize(f"  [!] RESULTS: {passed_count} / {total_tests} passed ({passed_count/total_tests*100:.1f}%)", Colors.YELLOW + Colors.BOLD if passed_count > 0 else Colors.RED + Colors.BOLD))
        print(colorize("=" * 65, Colors.BLUE))

    finally:
        # Cleanup executable
        if exe_path.exists():
            try:
                exe_path.unlink()
            except Exception:
                pass

if __name__ == "__main__":
    main()
