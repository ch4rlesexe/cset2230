#include <iostream>

int main() {
      unsigned short value = 0x0123;
      unsigned short n = 5;

      std::cout << "Origina lhaex: " << std::hex << value << " (";
      for (int i = 15; i >= 0; i--) std::cout << ((value >> i) & 1);
      std::cout << ")\n";

      unsigned short result = value | (1 << n);
      std::cout << "C++ Resulats" << std::hex << result << " (";
      for (int i = 15; i >= 0; --i) std::cout << ((result >> i) & 1);
      std::cout << ")\n";
      unsigned short asmr = value;
      __asm {
            mov ax, asmr
            mov cx, n
            bts ax, cx
            mov asmr, ax
      }
      std::cout << "Assembly Results in hex: " << std::hex << asmr << " (";
      for (int i = 15; i >= 0; --i) std::cout << ((asmr >> i) & 1);
      std::cout << ")\n";

      std::cout << "Do they match?: " << (result == asmr ? "YES" : "NO") << "\n";
      return 0;

}
