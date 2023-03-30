# PIPEX

This is my implementation of the pipex project for the Cursus 42 program. Pipex is a program that simulates the functionality of the shell command **|** (pipe).

<img width="997" alt="image" src="https://user-images.githubusercontent.com/113030191/226335526-8f8a9af2-5daf-4321-b05b-0e0919ecd480.png">

<p align="center">
<img width="614" alt="image" src="https://user-images.githubusercontent.com/113030191/226335850-90b32305-4851-4824-be4a-b5b882bf0dc9.png">
</p>

## Project Description

The pipex program takes in four arguments:

1. The input file
2. The first command to execute
3. The second command to execute
4. The output file

Pipex reads the input file and sends the output to the first command as standard input. The first command's output is sent as standard input to the second command. The second command's output is written to the output file.

## Usage

To compile the pipex program, run the following command: **make**

This will compile the program as **pipex**, which can be run on the command line.

To use the pipex program, run the following command:

        ./pipex file1 cmd1 cmd2 file2
        
Here, **file1** is the input file, **cmd1** is the first command to execute, **cmd2** is the second command to execute, and **file2** is the output file.

For example, to count the number of lines in a file using **wc -l**, we can use the following command:

      ./pipex file.txt "cat" "wc -l" out.txt

This will output the number of lines in **file.txt** to **out.txt**.

### Links to my other projects at 42:

- **[Main Page](../README.md)**
- **[libft](/libft-42)**
- **[ft_printf](/ft_printf)**
- **[get_next_line](/get_next_line)**
