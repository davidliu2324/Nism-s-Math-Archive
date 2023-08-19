#include <iostream>
#include <string>
#include <vector>
using namespace std;

string input_function() {
  string name_of_course{}, chat_gpt_entry{}, name_of_course_caps;
  cout << "Please enter the name of the course: "<< endl;
  cin >> name_of_course;
  cout << "Please copy and past the outline of all sections and topics provided by Chat GPT. Only include the sections and bullet lists, nothing else: "<< endl;
  cin >> chat_gpt_entry;
  for (int i = 0; i < name_of_course.size(); i++){
    if (i == 1 || name_of_course[i-1] == ' '){
      name_of_course_caps += toupper(name_of_course[i]);
    }
    else {
      name_of_course_caps += name_of_course[i];
    }
  }
  return name_of_course_caps, chat_gpt_entry;
  }

string html_converter(string name, string chat_gpt) {
  string final_code{};

}
