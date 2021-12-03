//---------------------------------------------------------------------------
#include "interfaces/t_factory.h"
#include "gr_elems/t_circle.h"
#include "gr_elems/t_rect.h"
//---------------------------------------------------------------------------



tst::i_item* tst::t_factory::create(const std::string& astr_elem_type, t_canvas* ap_canvas)
{
  if(astr_elem_type == "rect") {
    return new tst::t_rect(ap_canvas);
  }

  if(astr_elem_type == "circle") {
    return new tst::t_circle(ap_canvas);
  }

  return nullptr;
};
//---------------------------------------------------------------------------
