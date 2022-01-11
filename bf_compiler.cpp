#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stack>

using namespace std;
using std::cout;

void getSymbols(const string &line, map<int, char> &symbols, int &idx, int &comma, int &space)
{
  int count = 0;
  for(int i = 0, size = line.size(); i < size; i++){
    if(line[i] == ' ') space++;
    else if(line[i] != '+'){
      symbols[i+idx-space] = line[i];
    }
    if(line[i] == '.') comma++;
    count++;
  }
  idx += count;
  std::cout << line << std::endl;
}

void calcSymbols(const map<int, char> &symbols, vector<int> &output)
{
  int roop_count = 0, count_idx = 0, past_symbol_idx = 0, output_count = 0, size_count = 1;
  vector<int> counts(1);
  stack<int> roop_idx_stack;
  stack<int> roop_place_stack;
  auto roop_it = symbols.begin();

  int dot_count_for_debug = 0;
  for(auto it = symbols.begin(); it != symbols.end(); it++){
    if(it == symbols.end()) cout << "END" << endl;
    counts[count_idx] += it->first - past_symbol_idx - 1;
    past_symbol_idx = it->first;
    if(it->second == '>'){
      count_idx++;
      if(size_count < count_idx + 1) counts.push_back(0);
      continue;
    }
    else if(it->second == '<'){
      count_idx--;
      continue;
    }
    else if(it->second == '-'){
      counts[count_idx]--;
      continue;
    }
    else if(it->second == '['){
      roop_place_stack.push(it->first);
      continue;
    }
    else if(it->second == ']'){
      if(counts[count_idx] > 0){
        it = symbols.find(roop_place_stack.top());
        past_symbol_idx = it->first;
      } else {
        roop_place_stack.pop();
      }
      continue;
    }
    else if(it->second == '.'){
      dot_count_for_debug++;
      printf("%c", counts[count_idx]);
      output[output_count] = counts[count_idx];
      output_count++;
    }
  }
}

int main(int argc, char **argv)
{
  std::ifstream file;
  std::string file_name = argv[1];
  std::string path = "./../sample/examples/" + file_name;
  file.open(path, std::ios::in);
  int *ptr;
  int idx = 1, comma = 0, space = 0;
  map<int, char> symbols;
  vector<int> output;
  std::string line;
  while(std::getline(file, line)){
    getSymbols(line, symbols, idx, comma, space);
  }
  output.resize(1000);

  calcSymbols(symbols, output);
  cout << "size: " << output.size() << endl;

  return 0;
}