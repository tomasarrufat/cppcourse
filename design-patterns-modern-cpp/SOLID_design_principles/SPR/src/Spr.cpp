//Single Responsibility Principle Demonstration
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <boost/lexical_cast.hpp>

class Journal
{
private:
  std::string title;
  std::vector<std::string> entries;

public:
  explicit Journal(const std::string &title) : title{title}{}

  std::vector<std::string> getEntries() const;
  void add(const std::string &entry);
  // persistence is a separate concern
  void save(const std::string &filename);
};

std::vector<std::string> Journal::getEntries() const
{
  return entries;
}

void Journal::add(const std::string &entry)
{
  static int count = 1;
  entries.push_back(boost::lexical_cast<std::string>(count++) + ": " + entry);
}

void Journal::save(const std::string &filename)
{
  std::ofstream ofs(filename);
  for (auto &s : entries)
    ofs << s << std::endl;
}

class PersistenceManager
{
public:
  static void save(const Journal &j, const std::string &filename)
  {
    std::ofstream ofs(filename);
    for (auto &s : j.getEntries())
      ofs << s << std::endl;
  }
};

int main()
{
  Journal journal{"Dear Diary"};
  journal.add("Woke up hungry");
  journal.add("Ate breakfast");

  //Not recommended design 
  journal.save("auto_save_diary.txt");

  //Recommended design Single Responsibility Principle
  //PersistenceManager pm;
  PersistenceManager::save(journal, "pm_save_diary.txt");
}