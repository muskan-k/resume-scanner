									

								RESUME SCANNING SOFTWARE

NAME: MUSKAN KOTHARI
SECTION: N
SRN: PES1UG19CS284
ROLL NO: 6

This project scans .txt files for the entered pattern. File names with .txt extensions are entered as command line arguments as mentioned in the instructions file. After validating those, the program starts. This is a flexible, case-INSENSITIVE program since it asks the user what type of scanning they wish to apply. 
There are two options:
1. scanning only for 1 keyword
2. scanning for multiple keywords which further asks which logical operator to apply (AND/OR)

This project was programmed on MAC OS.
Possible constraints:

	1. While using multiple-keyword scanning please note:
 		For entering keywords do not use comma or space to separate them because it will be considered as one single keyword.
 		Type keyword one by one, pressing ENTER after each.
	2. Only file names present in the working directory will be opened. If entered otherwise, program will handle it.


Any known warnings or errors left after compiling and running the program: NONE
	Note:When this program was executed on ubuntu, the input for keyword(s) was skipped even on using fflush(stdin) or __fpurge(stdin). 
	This occurred on MAC as well but the error was cleared on using fflush(stdin) and worked perfectly after that without any warnings or errors.

Details about files and execution:
	Cproj.c - contains main funtion
	func.c - contains all defined functions 
	server.h - contains prototypes
	cmake.mk - executable make file

	Sample resume text files have been included in the project folder.
	resume0.txt, resume1.txt- Mechanical engineer
	resume2.txt- chef
	resume3.txt- software engineer
	resume4.txt, resume5.txt- Front-end developer

	Command for make file: make -f cmake.mk
	Run the program: ./scan (file names with extension)
			Example: ./scan resume0.txt resume1.txt (there is no restriction on number of files)

THANK YOU!



