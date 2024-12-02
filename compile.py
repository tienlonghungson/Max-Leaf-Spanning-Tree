import os
import subprocess

def compile_cpp(src_dir="src", output_dir="src/bin", executable_name="main"):
    # Create the output directory if it doesn't exist
    if not os.path.exists(output_dir):
        os.makedirs(output_dir)
    
    # Collect all .cpp files in the src directory and its subdirectories
    cpp_files = []
    for root, _, files in os.walk(src_dir):
        for file in files:
            if file.endswith(".cpp"):
                cpp_files.append(os.path.join(root, file))
    
    if not cpp_files:
        print("No .cpp files found in the src directory.")
        return
    
    # Construct the g++ command
    output_file = os.path.join(output_dir, executable_name)
    command = ["g++", "-std=c++20" ,"-o", output_file] + cpp_files

    try:
        # Execute the g++ command
        subprocess.run(command, check=True)
        print(f"Compilation successful! Executable created at: {output_file}")
    except subprocess.CalledProcessError as e:
        print(f"Compilation failed. Error: {e}")
    except FileNotFoundError:
        print("g++ not found. Ensure it is installed and in your PATH.")

if __name__ == "__main__":
    compile_cpp()

