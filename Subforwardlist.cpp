#include "subforwardlist.h"

subforwardlist::subforwardlist()
{
  next = nullptr;
}

bool subforwardlist::push_back(int d)
{
  if(next != nullptr)
  {
      subforwardlist* list = next;
      while(list->next != nullptr)
        list = list->next;

     list->data = d;

     subforwardlist* head = new subforwardlist;
     if(head == nullptr)
       return 1;

     list->next = head;
  }
  else
  {
      data = d;
      subforwardlist* head = new subforwardlist;
      if(head == nullptr)
        return 1;
      next = head;
  }

  return 0;
}

int subforwardlist::pop_back()
{
    if(next->next == nullptr)
    {
        delete next;
        next = nullptr;
        return data;
    }
    else
    {
        subforwardlist *list = next, *previous_list = next;
        while(list->next != nullptr)
        {
          list = list->next;
          if(list->next != nullptr)
            previous_list = list;
        }

        delete list;
        previous_list->next = nullptr;
        return previous_list->data;
    }
}

bool subforwardlist::push_forward(int d)
{
  subforwardlist *list = new subforwardlist;
  if(list == nullptr)
    return 1;

  list->next = next;
  list->data = data;
  data = d;
  next = list;
  return 0;
}

int  subforwardlist::pop_forward()
{
  int tmp = data;
  subforwardlist *list = next;
  next = list->next;
  data = list->data;
  delete list;
  return tmp;
}

bool subforwardlist::push_where(unsigned where, int d)
{
  subforwardlist *list = next, *insertion_list = new subforwardlist;

  if(insertion_list == nullptr)
    return 1;

  for(int i = 0; i < where - 2; i++)
    list = list->next;

  insertion_list->data = d;
  insertion_list->next = list->next;
  list->next = insertion_list;
  return 0;
}

bool subforwardlist::erase_where(unsigned where)
{
    if(next->next != nullptr)
    {
        subforwardlist *list = next, *previous_list = next;
        for(int i = 0; i < where - 1; i++)// возможно where надо заменить на where - 1
        {
            previous_list = list;
            list = list->next;
        }
           
        previous_list->next = list->next;
        delete list;
    }
    else
    {
        delete next;
        next = nullptr;
    }
  return 0;
}

unsigned subforwardlist::size()
{
  unsigned n = 1;
    
  if(next != nullptr)
  {
      subforwardlist* list = next;
      while(list->next != nullptr)
      {
        list = list->next;
        n++;
      }
  }

  return n; //возможно +-1
}

void subforwardlist::clear()
{
  if(next != nullptr)
  {
      subforwardlist* list = next, *previous_list= next;
      while(list->next != nullptr)
      {
        list = list->next;
        delete previous_list;
        previous_list = list;
      }
      delete list;
  }
  next = nullptr;
}

bool subforwardlist::init_from_file(char* filename)
{
  std::ifstream file;
  int tmp;
  file.open(filename);
  while(file >> tmp)
    push_forward(tmp);

  return 0;
}

subforwardlist::~subforwardlist()
{
}

