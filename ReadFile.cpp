#include "ReadFile.h"
#include <iostream>
#include <string>

ReadFile:: ReadFile()
{
   ReadFile* rf = new ReadFile;

   rf->input_file.open(file_name);
   rf->closed = false;
   rf->_eof = false;

   return rf;
}

ReadFile:: ~ReadFile()
{
   close(rf);
   delete rf;
}

bool ReadFile::eof()
{
   return rf->_eof;
}

void ReadFile::close()
{
   if (!rf->closed)
   {
      rf->input_file.close();
      rf->closed = true;
   }
}

String* ReadFile::readLine()
{
   if (rf->closed) return NULL;
   if (rf->_eof) return NULL;

   string text;
   rf->_eof = !(getline(rf->input_file, text));

   String* str = new String((const char*) text.c_str());
   return str;
}
