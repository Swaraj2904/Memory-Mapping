#include <iostream>
#include <cstdlib>
#include <math>
#include <fstream>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

using namespace std;

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
  int fd;
  struct stat sb;
  /* File initialized with 100,000 random integers */
  generate();
  /* Obtain the size of the file and use it to specify the size of
  the mapping and the size of the buffer to be written */
  if (fstat(fd, &sb) == -1)
    cout<< "Error in fstat" << endl;
  addr = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
  if (addr == MAP_FAILED)
    errExit("mmap");
  if (write(STDOUT_FILENO, addr, sb.st_size) != sb.st_size)
    fatal("partial/failed write");
  return 0;
}
