#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>


double poisson(double mu, int k) {
  return pow(mu, k) * exp(-mu) / tgamma(k+1);
}

double prob(std::vector<int> daten, double mu) {
  double L = 1;
  for(int k : daten){
    L *= poisson(mu, k);
  }
  return L;
}

int main() {
  std::ifstream fin("datensumme.txt");
  int n_i;
  std::vector<int> daten;
  for(int i = 0 ; i < 234 ; ++i) {
    fin >> n_i;
    daten.push_back(n_i);
  }
  fin.close();
  std::cout << prob(daten, 3.11538) << std::endl;

  std::ofstream fout("likelihood.txt");
  std::ofstream fout2("nll.txt");
  std::ofstream fout3("deltanll.txt");
  for(double mu = 0; mu <= 6; mu += 0.1) {
    fout << prob(daten, mu) << std::endl;
    fout2 << mu << " " << -2*log(prob(daten, mu)) << std::endl;
    fout3 << -2*log(prob(daten, mu)) + 2*log(prob(daten, 3.11538)) << std::endl;
  }
  fout.close();
  fout2.close();
  fout3.close();

  double L = 1;
  for(int k : daten){
    L *= poisson(k, k);
  }

  std::cout << -2*log(prob(daten, 3.11538)/L) << std::endl;
}