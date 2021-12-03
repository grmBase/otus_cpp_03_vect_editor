

#include "modules/t_engine.h"



// Запрос добавить элемент из меню, тулбара, по шорткату:
void tst::t_engine::on_click_add_elem(const std::string& a_str_elem_type)
{
  
};

// запрос на удалить элемент на который сейчас указывает мышка
void tst::t_engine::on_click_del(int an_x_pos, int an_y_pos)
{
};

// запрос на сохранение текущего документа в файл
int tst::t_engine::save_to_file(const std::string& a_str_file_name)
{

  std::string str_stream;

  for(auto& curr_elem : m_vec_elems) {

    /* ... getting final type of elem (rtty or use own virt function in i_item.h)

      -> std::string str_curr_elem_type;

      ... getting marshaling delegator for this elem (from some registry)

      -> std::string str_deleg_id_for_marshaling_of_this_type;

      i_marshal* p_marshal = factory.getObject(str_deleg_id_for_marshaling_of_this_type);

      p_marshal->serialize(curr_elem, str_stream);
    */

  }

  return 0;
};

// запрос на зачитывание документа с диска. Сначал очищает всё, потом загружает
int tst::t_engine::load_from_file(const std::string& a_str_file_name)
{

  // all should be clear before load
  clear();


  /*
    open file, load whole contents to str_stream;
  */

  std::string str_stream;
  size_t un_file_size; // got after reading whold content of file

  size_t un_position = 0;


  while(un_position < un_file_size) {

    /* 
      std::string strCurrType;
      oustream >> strCurrType;

      i_item* pItem = factory.createObject(strCurrType);

      i_marshal* p_marshal = factory.getObject(str_deleg_id_for_marshaling_of_this_type);

      size_t un_readed = p_marshal->restore(*pItem, str_stream, un_position);

      un_position += un_readed;
    */

  }

  return 0;
};

// реализуем обработчик GUI-ёв на перерисовку
void tst::t_engine::on_repaint()
{
};

