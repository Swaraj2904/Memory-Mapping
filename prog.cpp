#include <iostream>
#include <cstdlib>
#include <math>
#include <fstream>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

using namespace std;

/* Function to swap 2 integers */
void swap(int *a , int *b)
{
  *a = *a + *b;
  *b = *a - *b;
  *a = *a - *b;
}
/* Function to generate random numbers and store them in a file */
void generate()
{
  ofstream out;
  out.open("random.txt");
  for(int i = 1; i <= 100000; i++)
  {
    out << rand() << endl;
  }
  out.close();
}
public void main()
{
  char *addr;
  int fd, check;
  struct stat sb;
  int *array;
  /* File initialized with 100,000 random integers */
  generate();
  
  /* Opening file */
  fd = open("random.txt", O_RDWR)
  if(fd == -1)
    cout << "Error in opening the file" << endl;
    
  /* Obtain the size of the file and use it to specify the size of
  the mapping and the size of the buffer to be written */
  if (fstat(fd, &sb) == -1)
    cout << "Error in fstat" << endl;
  addr = mmap(NULL, sb.st_size, PROT_READ, MAP_SHARED, fd, 0);
  if (addr == MAP_FAILED)
    cout << "Error in mmap" << endl;
  if (write(STDOUT_FILENO, addr, sb.st_size) != sb.st_size)
    cout << "partial/failed write" << endl;
    
  /* Reading the mmap and sorting the integers in the mmap */
  sort(addr, addr + sb.st_size);
  
  /* Unmapping the memory map */
  check = munmap(addr, sb.st_size);
  if(check == -1)
    cout << "Error in munmap" << endl;
  return 0;
}
