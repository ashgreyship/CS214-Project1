# CS214_Project1
Methodology
a. Parameters
Your code will read the records through <standard input> (STDIN). Remember, the first record (line) is the column headings and should not be sorted as data. Your code must take in a command-line parameter to determine which value type (column) to sort on. If that parameter is not present (?-> throw an error, or default behavior). The first argument to your program will be '-c' to indicate sorting by column and the second will be the column name:
 
./sorter -c food
 
              Be sure to check the arguments are there and that they correspond to a listed value type (column heading) in the CSV.
 
             
b. Operation
Your code will be reading the CSV to be sorted from STDIN. In order to run your code to test it, you will need to open the CSV and read it in to the STDIN for your code:
 
cat input.file | ./sorter -c  movie_title      
 
The line above, if entered on the terminal, will open the file "input.file" and read it in to some executing code named "sorter", which was invoked with the parameters "-c" and "movie_title".
 
Your code's output will be a new CSV file outputted to STDOUT. You should output each record line by line using printf.
 
For testing purposes you can redirect STDOUT to a file:
 
cat input.file | ./sorter -c  movie_title      > sortedmovies.csv
 
 
c. Structure
Your code should use Mergesort to do the actual sorting of records. It is a powerful algorithm with an excellent average case.
 
It is strongly suggested that you use structs internally to represent each record in the CSV coming in as input.
 
In order to help you do both of these, please use a user-defined header file named sorter.h. We have attached one to the assignment description with some simple comments in it.
             
If you write any other definitions, typedefs, structs, unions or large helper functions (>~25 lines), be sure to put them in your header file and document them.
 
 
Results:
Submit your "sorter.c", "sorter.h" and "mergesort.c" as well as any other source files your header file references.
 
Document your design, assumptions, difficulties you had and testing procedure. Include any test CSV files you used in your documentation. Be sure to also include a short description of how to use your code. Look at the man pages for suggestions on format and content. Do not neglect your header file. Be sure to describe the contents of it and why you needed them.