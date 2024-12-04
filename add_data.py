import os
import glob

# Function to add content to the start of a file
def add_header_to_file(file_path, header):
    try:
        # Read existing content
        with open(file_path, 'r') as file:
            content = file.read()

        # Check if the file already contains the header
        if header.strip() in content:
            print(f"Header already present in {file_path}. Skipping.")
        else:
            # Write the new content with the header at the top
            with open(file_path, 'w') as file:
                file.write(header + content)
            print(f"Successfully added header to: {file_path}")
    
    except Exception as e:
        print(f"Error processing {file_path}: {e}")

# Function to read header content from an external file (e.g., header.txt)
def read_header_from_file(header_file_path):
    try:
        with open(header_file_path, 'r') as file:
            return file.read()
    except Exception as e:
        print(f"Error reading header from {header_file_path}: {e}")
        return None

# Function to check file extension and add the appropriate header
def add_header_based_on_extension(file_path, py_header, cpp_header):
    if file_path.endswith('.cpp'):
        add_header_to_file(file_path, cpp_header)
        
    elif file_path.endswith('.py'):
        add_header_to_file(file_path, py_header)
        
    else:
        print(f"Skipping file (unsupported extension): {file_path}")

# Recursive function to process all .cpp and .py files in the folder and its subfolders
def process_files_in_folder(folder_path, py_header, cpp_header):
    # Ensure the folder exists
    if not os.path.exists(folder_path):
        print(f"Folder not found: {folder_path}")
        return

    # Iterate over all files and subdirectories in the folder
    for root, dirs, files in os.walk(folder_path):
        for file in files:
            file_path = os.path.join(root, file)
            add_header_based_on_extension(file_path, py_header, cpp_header)

# Example usage
folder_path = r".\Experimentfolder"  # Folder path where .py and .cpp files are located
py_header_file_path = r".\py_header.txt"   # Path to the file containing the header content
cpp_header_file_path = r".\cpp_header.txt"   # Path to the file containing the header content

# You can either read headers from a file or define them directly
py_header = read_header_from_file(py_header_file_path)
cpp_header = read_header_from_file(cpp_header_file_path)

process_files_in_folder(folder_path, py_header, cpp_header)