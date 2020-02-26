#pragma once

#include <fstream>

class subforwardlist
{
public:
  subforwardlist();
  bool push_back(int d);
  int pop_back();
  bool push_forward(int d);
  int  pop_forward();
  bool push_where(unsigned where, int d);
  bool erase_where(unsigned where);
  unsigned size();
  void clear();
  bool init_from_file(char* filename);
  ~subforwardlist();
private:
  int data;
  subforwardlist* next;
};
