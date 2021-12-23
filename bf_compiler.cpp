#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stack>

using namespace std;

void getSymbols(const string &line, map<int, char> &symbols, int &idx, int &comma)
{
  int count = 0;
  for(int i = 0, size = line.size(); i < size; i++){
    if(line[i] != '+'){
      symbols[i+idx] = line[i];  // スペースに対応できてない
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
  for(auto it = symbols.begin(); it != symbols.end(); it++){
    // cout << "first: " << it->second << endl; 
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
      // cout << "roop: " << counts[count_idx] << endl;
      continue;
    }
    else if(it->second == '['){
      roop_idx_stack.push(count_idx);
      roop_place_stack.push(it->first);
      cout << "QQ: " << roop_place_stack.top() << endl;
      continue;
    }
    else if(it->second == ']'){
      //cout << "sta" << counts[roop_idx_stack.top()] << endl;
      if(counts[roop_idx_stack.top()] != 0){
        it = symbols.find(roop_place_stack.top());  // ここから！！！
        //cout << "roop: " << roop_place_stack.top() << endl;
        past_symbol_idx = it->first;
      } else {
        //cout << "A" << endl;
        roop_idx_stack.pop();
        roop_place_stack.pop();
        //cout << "S" << endl;
      }
    // cout << "F: " << roop_idx_stack.size() << endl;
      continue;
    }
    else if(it->second == '.'){
        // cout << "D" << endl;
        // cout << "num: " << counts[count_idx] << endl;
        // cout << "num0: " << counts[0] << endl;
        // cout << "num1: " << counts[1] << endl;
        // cout << "num2: " << counts[2] << endl;
        // cout << "idx: " << count_idx << endl;
      printf("%c", counts[count_idx]);
    }
  }
}

int main(int argc, char *argv[])
{
  std::ifstream file;
  std::string filename = "./../sample/examples/test.bf";
  file.open(filename, std::ios::in);
  int *ptr;
  int idx = 1, comma = 0;
  map<int, char> symbols;
  vector<int> output;
  std::string line;
  while(std::getline(file, line)){
    getSymbols(line, symbols, idx, comma);
  }
  output.resize(comma);
  calcSymbols(symbols, output);
//   for(int i = 0, size = output.size(); i < size; i++){
//     //cout << "output: " << output[i] << endl;
//     //printf("%c", output[i]);
//   }

  return 0;
}
