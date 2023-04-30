#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

void print_image(int &error)
{
    if (error == 1)
    {
        std::cout << "------------------" << std::endl;
        std::cout << "\n\n\n\n\n\n\n"
                  << std::endl;
    }
    else if (error == 2)
    {
        std::cout << "------------------" << std::endl;
        std::cout << "        |" << std::endl;
        std::cout << "\n\n\n\n\n\n"
                  << std::endl;
    }
    else if (error == 3)
    {
        std::cout << "------------------" << std::endl;
        std::cout << "        |" << std::endl;
        std::cout << "        |" << std::endl;
        std::cout << "\n\n\n\n\n"
                  << std::endl;
    }
    else if (error == 4)
    {
        std::cout << "------------------" << std::endl;
        std::cout << "        |" << std::endl;
        std::cout << "        |" << std::endl;
        std::cout << "        |" << std::endl;
        std::cout << "\n\n\n\n"
                  << std::endl;
    }
    else if (error == 5)
    {
        std::cout << "------------------" << std::endl;
        std::cout << "        |" << std::endl;
        std::cout << "        |" << std::endl;
        std::cout << "        |" << std::endl;
        std::cout << "        O" << std::endl;
        std::cout << "      | | |" << std::endl;
        std::cout << "        |" << std::endl;
        std::cout << "       / /" << std::endl;
    }
}

bool get_repeat(const std::vector<char> &word_user) // узнаем а надо ли продолжать
{
    for (auto itr = word_user.begin(); itr != word_user.end(); itr++)
    {
        if (*itr == '-')
            return true;
    }
    return false;
}

void print_text(const std::vector<char> &word_user, char &letter, int &error) // печатаем текст
{
    system("clear");
    if (error > 0)
        print_image(error);
    for (auto itr = word_user.begin(); itr != word_user.end(); itr++)
    {
        std::cout << *itr;
    }
    std::cout << "\n";
    if (error != 5)
    {
        std::cout << "Введите букву: ";
        std::cin >> letter;
    }
}

int main()
{
    std::vector<std::string> words; //общий словарь
    words.push_back("think");
    words.push_back("differ");
    words.push_back("move");
    words.push_back("long");
    words.push_back("make");
    words.push_back("look");
    words.push_back("answer");
    srand(static_cast<unsigned>(time(0))); //чтоб размесить слова, можно прикрутить чтоб слова брал из файлика
    std::random_shuffle(words.begin(),words.end()); // мешает слова
    std::string word = words[0];
    std::vector<char> word_user;

    for (int i = 0; i < word.length(); i++) // сделали столько тире сколько букв
    {
        word_user.push_back('-');
    }

    char letter;
    bool repeat = true, error_fl = true;
    int error = 0;
    while (repeat)
    {

        repeat = false;
        error_fl = true;
        print_text(word_user, letter, error); //рисуем
        if (error == 5)
        {
            std::cout << "Вы проиграли" << std::endl;
            repeat = true;
            break;
        }
        for (int i = 0; i < word.length(); i++) //проверяем совпадение букв
        {
            if (word[i] == letter)
            {
                word_user[i] = letter;
                error_fl = false;
            }
        }
        if (error_fl)
            error++;
        repeat = get_repeat(word_user); // узнаем а надо ли продолжать
    }
    if (!repeat)
    {
        std::cout << "Вы победили!!!"<< std::endl;
    }
}