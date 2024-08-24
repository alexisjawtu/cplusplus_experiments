// ofstream::open / ofstream::close
#include <fstream>      // std::ofstream

int main () {

  std::ofstream ofs;
  ofs.open("alexis/test.txt", std::ofstream::out | std::ofstream::app);

  ofs << "second lorem ipsum\n";

  ofs.close();

  return 0;
}