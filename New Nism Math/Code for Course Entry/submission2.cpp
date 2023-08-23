//All authored by David Liu
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string list_code_converter(string section, vector<string> sub_sections){
  string section_html{};
  string output{};
  section_html += "<a href=\"#\" class=\"topic-btn fourth-heading\">" + section + "</a>\n";
  for (int i= 0; i < sub_sections.size(); i++){
    section_html += "<li class=\"topic-list-item\"><a; href=\"#\" class=\"list-item-link\">" + sub_sections[i] + "</a>\n</li>\n";
  }
  output = "<ul>" + section_html + "</ul>\n";
  return output;
}

vector<string> sub_topic_list_creator(string entry){
  vector<string> sub_topic_list{};
  for (int i = 0; i < entry.length() - 1; i++){
    string topic_iteration{};
    if (entry[i] == '_'){
      sub_topic_list.push_back(topic_iteration);
      topic_iteration = "";
    }
    if (i == entry.length() -1){
      topic_iteration += entry[i];
      sub_topic_list.push_back(topic_iteration);
    }
    else {
      topic_iteration += entry[i];
    }
  }
  return sub_topic_list;
}

//Input function, is meant to extract both main sections and sub-topics of each section
//Remember that when inputting the name of the sections, different sections are separated by an underscore, and regular spaces are typed in as normal
string input_function(){
  string course_name{};
  string section_list_html{};
  int amount_of_sections{};

  cout << "Enter the name of the course (Please Capitalize Appropriately):\n";
  getline(cin,course_name);

  cout << "Enter the amount of main sections in the course (NOT SUB-TOPICS):\n";
  cin >> amount_of_sections;

  for (int i = 0; i < amount_of_sections -1; i++){
    string section_iteration{};
    string sub_topic_iteration{};
    cout << "Enter the next section (In order please): "<< endl;
    getline(cin, section_iteration);

    //extracting the sub-topics of the section iteration
    cout << "Enter the sub-sections of this section, separated by an underscore '_' and you may type in spaces as you normally would: "<< endl;
    getline(cin, sub_topic_iteration);

    //getting the list of sub-topics for this section iteration
    vector<string> sub_topic_list = sub_topic_list_creator(sub_topic_iteration);

    string html_iteration = list_code_converter(section_iteration, sub_topic_list);
    section_list_html += html_iteration;
  }

  return course_name, section_list_html;
}

string main_code_converter(string name, string list_html) {
  string final_html{};
  final_html = "<div class=\"course-page-layout\">\n<section>\n<div class=\"course-title-heading\">\n<h3 class=\"course-title heading-secondary\">" + name +"</h3>\n</div>\n<div class=\"course-content\">\n<div class=\"course-topics\">" + list_html + "</div>\n</div>\n</section>";
  return final_html;
}

int main() {
  string course_name, section_list_html = input_function();
  string left_side_html = main_code_converter(course_name, section_list_html);
  cout << left_side_html;
  return 0;
}