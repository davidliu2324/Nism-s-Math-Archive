//All authored by David Liu
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string list_code_converter(vector<string> section, vector<string> sub_topic_list){
    string current_list_code{};
    string output{};
    for (int i=0; i < section.size(); i++){
        current_list_code += "<a href=\"#\" class=\"topic-btn fourth-heading\">" + section[i] + "</a>";
        for (int j =0; j < sub_topic_list.size(); j++){
            current_list_code += "<li class=\"topic-list-item\"><a; href=\"#\" class=\"list-item-link\">" + sub_topic_list[j];
            current_list_code += "</a></li>" + '\n';
        }
    }
    output = '\n' + "<ul>" + '\n' + current_list_code + '\n' + "</ul>" + '\n';
    return output;
}

//Input function, is meant to extract both main sections and sub-topics of each section
//Remember that when inputting the name of the sections, different sections are separated by an underscore, and regular spaces are typed in as normal
string input_function() {
    string course_name{}, main_sections{}, list_code{};
    vector<string> course_sections{};
    //First start with name of the course
    cout << "Enter the name of the course: " << endl;
    getline(cin,course_name);

    //Second, all the main sections of the course, not the sub-topics
    //These will all be added to the course_sections vector list
    cout << "Enter all the main sections (NOT THE SUB-TOPICS), separated by an underscore '_'. You may type in spaces as you normally would: " << endl;
    getline(cin,main_sections);

    //main_section_entry variable is used to add the entries into the main_sections vector
    string main_section_entry{};
    for (int i = 0; i < main_sections.length(); i++) {
        if (main_sections[i] == '_') {
            course_sections.push_back(main_section_entry);
            main_section_entry = "";
            continue;
        }
        if (i == main_sections.length() - 1) {
            main_section_entry += main_sections[i];
            course_sections.push_back(main_section_entry);
            main_section_entry= "";
            //continue;
        }

        else {
            main_section_entry += main_sections[i];
        }
    }

    //Input for sub-topics of each section
    string sub_section_entries{};
    vector<string> sub_sections{};
    string sub_section_item{};
    string current_list_code{};
    for (int k = 0; k < course_sections.size(); k++) {
        cout << "Enter the sub-sections of this section: " << course_sections[k] << endl << "Separated by an underscore '_' and you may type in spaces as you normally would:" << endl;
        getline(cin,sub_section_entries);

        //This is for adding the sub sections to a vector
        for (int j = 0; j < sub_section_entries.length(); j++) {
            if (sub_section_entries[j] == '_') {
                sub_sections.push_back(sub_section_item);
                sub_section_item = "";
                continue;
            }

            //CODE CONVERTER ONLY IN LIST FORM
            if (j == sub_section_entries.length() - 1) {
                sub_section_item += sub_section_entries[j];
                sub_sections.push_back(sub_section_item);
                //Insert code converter below with arguments sub_sections and main_sections[i]//
                current_list_code = list_code_converter(course_sections, sub_sections);
                list_code += '\n' + current_list_code;
                break;
                //Insert code above//
            }
            else {
                sub_section_item += sub_section_entries[j];
            }
        }
    }
    return list_code, course_name;
}

string main_code_builder(string list, string name) {
    string fully_built_html_code = "<div class=\"course-page-layout\">\n<section>\n<div class=\"course-title-heading\">\n<h3 class=\"course-title heading-secondary\">" + name + "</h3>\n" + list + "\n</div>\n</div>\n</section>\n</div>";
    return fully_built_html_code;
}

string textbook_resources_input() {
    string textbook_list_code{};
    char textbook_question{};
    cout << "Do you have any textbook resources and their links thus far? Answer 'y'/'n': " << endl;
    cin >> textbook_question;
    if (textbook_question == 'N' || textbook_question == 'n') {
        string default_textbook_code = "<section class=\"textbook - links\">\n< h3 class = \"textbook-links-title heading-secondary\" > Texbook Resources< / h3>\n<div class = \"textbook-content-box\">\n<div class = \"textbook-list\">\n<ul><li class = \"textbook-list-item\">\n<a href = \"#\" class = \"list-item-link\">< / a>\n< / li>\n< / ul>\n< / div>\n< / div>\n< / section>";
        return default_textbook_code;
    }
    if (textbook_question == 'Y') {
        string textbook_titles{};
        vector<string> textbook_title_list{};
        cout << "Enter the name of the textbook(s), and separate the separate textbook names with underscores '_'. Enter spaces as you normally would for the titles: " << endl;
        cin >> textbook_titles;
        string current_textbook{};

        // loop to add textbook titles into a list
        for (int i = 0; i < textbook_titles.length(); i++) {
            if (textbook_titles[i] == '_' || i == textbook_titles.length() - 1) {
                textbook_title_list.push_back(current_textbook);
                current_textbook = "";
            }
            else {
                current_textbook += textbook_titles[i];
            }
        }
        for (int j = 0; j < textbook_title_list.size(); j++) {
            char textbook_links{};
            string weird_string = "class=\"list-item-link\">";
            cout << "Enter the link of this textbook: " + textbook_title_list[j] + " below";
            cin >> textbook_links;
            textbook_list_code += "<li class=\"textbook-list-item\">\n<a href=\"" + textbook_links + '\"' + weird_string + textbook_title_list[j] + "< / a>\n< / li>";
        }
        string final_textbook_code = "<section class=\"textbook-links\">\n<h3 class = \"textbook-links-title heading-secondary\">Texbook Resources</h3>\n<div class=\"textbook-content-box\">\n<div class=\"textbook-list\">\n<ul>" + textbook_list_code + "</ul>\n</div>\n</div>\n</section>";
        return final_textbook_code;
    }


}

int main() {
    string list_code, course_title = input_function();
    string left_section = main_code_builder(list_code, course_title);
    string right_section = textbook_resources_input();
    string final_code_layout = left_section + '\n' + right_section;
    cout << final_code_layout;
}