#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char *argv[]) {
  int n, m ,c, consumption, device, maxConsumption, i;
  std::vector<int> consumptions;
  std::vector<int> devices;
  i = 0;
  while(std::cin >> n >> m >> c, (n != 0) && (m != 0) & (c != 0)) {
    ++i;
    consumptions.clear();
    devices.clear();

    for(device = 0; device < n; device++) {
      devices.push_back(0);
    }

    while(n > 0) {
      std::cin >> consumption;
      consumptions.push_back(consumption);
      n--;
    }

    maxConsumption = 0;
    consumption = 0;
    while(m > 0) {
      std::cin >> device;
      if(devices[device - 1] == 0) {
        consumption += consumptions[device - 1];
        devices[device - 1] = 1;
      } else {
        devices[device - 1] = 0;
        consumption -= consumptions[device - 1];
      }
      if(consumption > maxConsumption) {
        maxConsumption = consumption;
      }
      m--;
    }

    std::cout << "Sequence " << i << std::endl;
    if(maxConsumption > c) {
      std::cout << "Fuse was blown." << std::endl;
    } else {
      std::cout << "Fuse was not blown." << std::endl;
      std::cout << "Maximal power consumption was " << maxConsumption << " amperes." << std::endl;
    }
    std::cout << std::endl;

  }
  return 0;
}
