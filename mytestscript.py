import subprocess
from colorama import Fore, Back, Style

def run_cpp_program(input_data):
    command = ['./MatrixCalculator']  # assuming you compiled the C++ program to an executable named 'simple_program'
    process = subprocess.Popen(command, stdin=subprocess.PIPE, stdout=subprocess.PIPE, text=True)
    output, _ = process.communicate(input=input_data)
    return output.strip()  # Remove leading/trailing whitespaces

def compare_output(expected_output, actual_output):
    return expected_output == actual_output

def main():
    # Test Addition
    test_input = "[1 1 1, 1 1 1, 1 1 1]\n+\n[1 1 1, 1 1 1, 1 1 1]\n"
    expected_output = "[2 2 2, 2 2 2, 2 2 2]"
    actual_output = run_cpp_program(test_input)
    print(f"{Fore.GREEN}PASS{Style.RESET_ALL}" if compare_output(expected_output, actual_output) else f"{Fore.RED}FAIL{Style.RESET_ALL}")

    # Test Subtraction
    test_input = "[1 1 1, 1 1 1, 1 1 1]\n-\n[1 1 1, 1 1 1, 1 1 1]\n"
    expected_output = "[0 0 0, 0 0 0, 0 0 0]"
    actual_output = run_cpp_program(test_input)
    print(f"{Fore.GREEN}PASS{Style.RESET_ALL}" if compare_output(expected_output, actual_output) else f"{Fore.RED}FAIL{Style.RESET_ALL}")

    # Test Multiplication
    test_input = "[1 2 3, 4 5 6, 7 8 9]\n*\n[9 8 7, 6 5 4, 3 2 1]\n"
    expected_output = "[30 24 18, 84 69 54, 138 114 90]"
    actual_output = run_cpp_program(test_input)
    print(f"{Fore.GREEN}PASS{Style.RESET_ALL}" if compare_output(expected_output, actual_output) else f"{Fore.RED}FAIL{Style.RESET_ALL}")

    # Test Transpose
    test_input = "[1 2 3, 1 2 3, 1 2 3]\nT\n"
    expected_output = "[1 1 1, 2 2 2, 3 3 3]"
    actual_output = run_cpp_program(test_input)
    print(f"{Fore.GREEN}PASS{Style.RESET_ALL}" if compare_output(expected_output, actual_output) else f"{Fore.RED}FAIL{Style.RESET_ALL}")

    # Test Determinant
    test_input = "[1 2, 3 4]\nD\n"
    expected_output = "-2"
    actual_output = run_cpp_program(test_input)
    print(f"{Fore.GREEN}PASS{Style.RESET_ALL}" if compare_output(expected_output, actual_output) else f"{Fore.RED}FAIL{Style.RESET_ALL}")

    # Test Inverse
    test_input = "[1 2, 3 4]\nD\n"
    expected_output = "[-2 1, 1.5 -0.5]"
    actual_output = run_cpp_program(test_input)
    print(f"{Fore.GREEN}PASS{Style.RESET_ALL}" if compare_output(expected_output, actual_output) else f"{Fore.RED}FAIL{Style.RESET_ALL}")
    

if __name__ == "__main__":
    main()
