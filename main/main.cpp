#include <iostream>

#include "main/work_obj.h"

// some canvas is usually provided for GUI application
class t_canvas;



int main(int, const char* [])
{

  t_canvas* ap_canvas = nullptr;  // in reality it should not be nullptr for sure
  

  t_work_obj workObj(ap_canvas);

  try 
  {

    // here some gui loop with handlers

    int nEventCode = 0;
    switch (nEventCode) {
    case 0:
    {
      workObj.on_add_elem();
    }
    break;

    case 1:
    {
      workObj.on_del_elem();
    }
    break;

    case 2:
    {
      workObj.on_load_from_file();
    }
    break;


    case 3:
    {
      workObj.on_save_to_file();
    }
    break;


    }
    // sometimes some requests are happens to us:

  }
  catch(const std::exception& exc)
  {
    std::cout << "Exception caught. Info: " << exc.what() << std::endl;
    return -33;
  }

  return 0;
}
//-----------------------------------------------------------------------------

