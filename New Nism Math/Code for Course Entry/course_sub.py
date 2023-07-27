#All Authored By NISM (David Liu)


def input_function():
    progress = 1 #To keep track of the nth course that the user has entered so far
    progress_string = '1st'
    list_progress = 0

    #course outlines are separated by main sections and sub-sections, for example in Calculus 1, a main section would be 'integrals' and a sub-section would be 'integration by parts'
    main_sections = []
    sub_sections = []

    #exits are for ending the loop in the submission process
    main_exit = False
    sub_section_exit = False
    course_title = str(input('Enter the name of the course '))

    while not main_exit:
        sub_section_exit = False
        course_main_section = str(input(f'Enter the {progress_string} section of the course: '))
        main_sections.append(course_main_section)

        while not sub_section_exit:
            sub_section_entry = str(input("Enter a sub-section (in order and one at a time): "))
            sub_sections.append(sub_section_entry)
            sub_exit_question = str(input("Is this the last sub-section of this main section? (enter 'y' or 'n): "))
            sub_exit_question = sub_exit_question.upper()
            if sub_exit_question == 'Y': #exiting out of the sub_section
                exit_question = str(input("Is this the last section? (enter 'y' or 'n'): "))#exiting out of the main_section
                exit_question = exit_question.upper()
                if exit_question == 'Y':
                    main_exit = True
                elif exit_question == 'N':
                    main_exit = False
                progress += 1
                progress_string = str(progress)+"th"
                sub_section_exit = True
            elif sub_exit_question == 'N':
                sub_section_exit = False
    return course_title, main_sections, sub_sections


def code_converter(course_name, main_section_list, sub_section_list): #Converting both main and sub sections lists into html code.
    course_title_code = f'<h3 class="course-title heading-secondary">{course_name}</h3>\n'
    main_sub_code = ''
    closing_code = '\n</div>\n</div>\n</section>'
    for i in range(len(main_section_list)):
        main_sub_code += f'<a href="#" class="topic-btn fourth-heading">{main_section_list[i]}</a>\n<ul class="topic-list">\n'
        for j in range(len(sub_section_list)):
            main_sub_code += f'<li class="topic-list-item"><a href="#" class="list-item-link">{sub_section_list[j]}</a></li>'
            if j == len(sub_section_list) - 1:
                main_sub_code += '\n</ul>'

    final_code = f'<section>\n{course_title_code}<div class="course-content">\n<div class="course-topic">\n{main_sub_code}\n{closing_code}'
    return final_code

def file_exporter(x):
    file = open('Code for Course Entry\code_file.txt','w')
    file.write(x)

def main():
    course_title, main_sections, sub_sections = input_function()
    converted_code = code_converter(course_title,main_sections,sub_sections)
    file_exporter(converted_code)
main()
#All Authored By NISM (David Liu)