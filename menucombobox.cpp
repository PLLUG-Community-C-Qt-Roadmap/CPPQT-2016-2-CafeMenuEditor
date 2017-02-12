#include "menucombobox.h"

#include "menuiterator.h"

/*!
 * \brief Публічний конструктор.
 * \param parent Батьківський віджет.
 */
MenuComboBox::MenuComboBox(QWidget *parent)
    : QComboBox(parent),
      mRoot{nullptr}
{
}

/*!
 * \brief Встановлює кореневий елемент у меню (той елемент який містить усі інші),
 *  та оновлює QComboBox.
 * \param menu Вказівник на Compositor - кореневий елемент у єрархії нашого меню.
 */
void MenuComboBox::setMenu(AbstractMenuItem *menu)
{
    mRoot = menu;
    clear();  // Очищаємо QComboBox
    mItemByIndex.clear(); // Видаляємо усі елементи з QHash
    populateComboBox(); // Наповнюємо QComboBox заново
}

AbstractMenuItem *MenuComboBox::currentMenuItem() const
{
    int itemId = currentData().toInt();
    return mItemByIndex.value(itemId);
}

void MenuComboBox::clearData()
{
    clear();
    mItemByIndex.clear();
}

void MenuComboBox::updateComboBox()
{
    clear();
    populateComboBox();
}


void MenuComboBox::populateComboBox()
{
    if (mRoot) // Перевіряємо чи кореневий елемент встановлено
    {
        MenuIterator iterator(mRoot); // Створюємо ітератор для меню.
        while (iterator.hasNext())  // Якщо елемент є
        {

            AbstractMenuItem * item = iterator.next(); //  Беремо елемент, і пересуваємо ітератор на наступний
            // Додаємо елементи у QHash
            // To be able to access certain menu item by item id taken from QComboBox item data.
            int itemId = mItemByIndex.size();   // When QHash is empty id will be 0, when one element
                                                // element added - id will be 1, ...
                                                //So every new element will get unique number as an id.

            mItemByIndex.insert(itemId, item); // Add id - item pair.

            // Add item to combo box.
            addItem(item->title().c_str(), itemId);
        }
    }
}

bool MenuComboBox::checkDublicate(std::string tempTitle)
{
    if (mRoot) // Перевіряємо чи кореневий елемент встановлено
    {
        MenuIterator iterator(mRoot); // Створюємо ітератор для меню.
        while (iterator.hasNext())  // Якщо елемент є
        {

            AbstractMenuItem * item = iterator.next(); //  Беремо елемент, і пересуваємо ітератор на наступний
            if(item->title()==tempTitle) // Якщо елемент містить title такий як і в елемента що додається повертаємо false
                return false;
        }
        return true;
    }
}


