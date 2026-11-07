#include <iostream>
#include <fstream>
using namespace std;

int wordCount(fstream&);
int huntForChar(fstream&, char);
void differences(fstream&, fstream &);
void setToBeginning(fstream &);


int main() {
  fstream file1;
  fstream file2;
  string filename1;
  string filename2;
  char find;

  cout << "Which file to open for file 1? ";
  cin >> filename1;
  cout << "Which file to open for file 2? ";
  cin >> filename2;
  cout << "What character do you want to look for? ";
  cin >> find;
  file1.open(filename1, ios::in);
  file2.open(filename2, ios::in);

  if (!file1.is_open() || !file2.is_open()) {
    cout << "Could not open files." << endl;
    return 0;
  }
  cout << "Summary\n=======\n";
  cout << "File: " << filename1 << endl;
  //

  int location1 = huntForChar(file1, find);
  if( location1 == -1 ) {
    cout << find << " not found\n";
  }
  else {
    cout << find << " first found at position " << location1 << endl;
  }
  cout << "Words: " << wordCount(file1) << endl;

  cout << endl << "File: " << filename2 << endl;
  //

  int location2 = huntForChar(file2, find);
  if( location2 == -1 ) {
    cout << find << " not found\n";
  }
  else {
    cout << find << " first found at position " << location2 << endl;
  }
  cout << "Words: " << wordCount(file2) << endl;
  
  //cout << "Differences:" << endl;
  //differences(file1, file2);

  file1.close();
  file2.close();

  return 0;
}

int wordCount(fstream & file) {
  setToBeginning(file);
  int count = 0;
  string word;
  while (file >> word) {
    count++;
  }
  return count;
}

int huntForChar(fstream & file, char target) {
  char ch;
  int position = 0;
  setToBeginning(file);

  while (file.get(ch)) {
    if (ch == target) {
      return position;
    }
    position++;
  }
  return -1;
}

void differences(fstream & file1, fstream & file2) {
  int current1;
  int current2;
  bool foundDifference = false;
  setToBeginning(file1);
  setToBeginning(file2);
  current1 = file1.peek();
  current2 = file2.peek();
  while(current1 != EOF || current2 != EOF) {
    if(current1!=EOF) {
      current1=file1.get();
    }
    if(current2!=EOF) {
      current2=file2.get();
    }
    if (current1 != current2) {
      cout << endl;
      foundDifference = true;
      if( current1!=EOF ) {
        cout << (char) current1;
      }
      else {
        cout << "(Nothing)";
      }
      cout << " vs ";
      if( current2!=EOF ) {
        cout << (char) current2;
      }
      else {
        cout << "(Nothing)";
      }
    }
  }
  if (!foundDifference) {
    cout << "NO DIFFERENCE FOUND!" << endl;
  }
}

void setToBeginning(fstream & stream) {
  stream.clear();
  stream.seekg(0);
}
