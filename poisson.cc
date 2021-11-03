#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

double poisson(double mu, int k) {
  return pow(mu, k) * exp(-mu) / tgamma(k+1);
}

int main() {
  std::ifstream fin("datensumme.txt");
  int n_i;
  std::vector<int> zaehler(11);
  for(int i = 0 ; i < 234 ; ++i) {
    fin >> n_i;
    zaehler[n_i] += 1;
  }
  fin.close();
  std::ofstream fout("hist.txt");
  std::ofstream fout2("histpoi.txt");
  for (unsigned int k = 0; k < zaehler.size(); k++) {
    std::cout << k << ":" << zaehler[k] << std::endl;
    fout << k << " " << zaehler[k] << std::endl;
    fout2 << k << " " << zaehler[k] << " " << 234 * poisson(3.11538, k) << std::endl;
  }
  fout.close();
  fout2.close();
}