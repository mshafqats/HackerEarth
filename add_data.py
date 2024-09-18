import os
import glob

# Function to add content to the start of a file
def add_header_to_file(file_path, header):
    try:
        # Read the existing content of the file
        with open(file_path, 'r') as file:
            content = file.read()

        # Write the new content with the header at the top
        with open(file_path, 'w') as file:
            file.write(header + content)
        
        # Notify successful header addition
        print(f"Successfully added header to: {file_path}")
    
    except Exception as e:
        # Catch and display any errors during file processing
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
def add_header_based_on_extension(file_path, py_header):
    # Check if the file has a .cpp extension
    if file_path.endswith('.cpp'):
        cpp_header = '''/*
=====================
|  ID:   mshafqats  |
|  LANG: C++        |
=====================
Mohammad Shafqat Siddiqui
*/

'''
        add_header_to_file(file_path, cpp_header)
        
    # Check if the file has a .py extension
    elif file_path.endswith('.py'):
        # Use the header from the external file
        add_header_to_file(file_path, py_header)
        
    else:
        # Skip files with unsupported extensions
        print(f"Skipping file (unsupported extension): {file_path}")

# Function to process all .cpp and .py files in the folder
def process_files_in_folder(folder_path, header_file_path):
    # Read the header data from the external file
    py_header = read_header_from_file(header_file_path)
    
    if py_header is None:
        print("No header to add. Exiting.")
        return
    
    # Ensure the folder exists
    if not os.path.exists(folder_path):
        print(f"Folder not found: {folder_path}")
        return

    # Search for all files in the folder (using glob to match file patterns)
    file_paths = glob.glob(os.path.join(folder_path, '*.*'))
    
    # If no files are found, notify the user
    if not file_paths:
        print(f"No files found in {folder_path}")
        return

    # Process each file one by one
    for file_path in file_paths:
        add_header_based_on_extension(file_path, py_header)

# Example usage
folder_path = r".\Experimentfolder"  # Folder path where .py files are located
header_file_path = r".\header.txt"   # Path to the file containing the header content
process_files_in_folder(folder_path, header_file_path)
