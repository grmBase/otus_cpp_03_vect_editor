//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <string>
//---------------------------------------------------------------------------
#include "i_item.h"  // реализация прям тут же
//---------------------------------------------------------------------------
class t_canvas;
//---------------------------------------------------------------------------


namespace tst
{


// фабрика, создающая графические объекты
// В реальной жизни лучше на неё сделать интерфейс, а реализацию утащить в модули
class t_factory
{
  public:

    t_factory(/*возможно с каким-то путём к каталогу с "плагинами"*/) {};

    i_item* create(const std::string& astr_elem_type, t_canvas* ap_canvas);

  private:

    // тут может быть по всякому, может быть мэп с указателями на функции
    // из плагинов
};


}
//---------------------------------------------------------------------------