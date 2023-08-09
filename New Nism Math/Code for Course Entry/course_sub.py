#All Authored By NISM (David Liu)


def input_function():
    progress = 1 #To keep track of the nth course that the user has entered so far
    progress_string = '1st'
    list_progress = 0
    course_section_html = ''

    #exits are for ending the loop in the submission process
    main_exit = False
    sub_section_exit = False
    course_title = str(input('Enter the name of the course '))

    while not main_exit:
        sub_sections = []
        sub_section_exit = False
        course_main_section = str(input(f'Enter the {progress_string} section of the course: '))
        course_section_html += f'<a href="#" class="topic-btn fourth-heading">{course_main_section}</a>\n<ul class="topic-list">\n'

        while not sub_section_exit:
            sub_section_entry = str(input("Enter a sub-section (in order and one at a time): "))
            sub_sections.append(sub_section_entry)
            sub_exit_question = str(input("Is this the last sub-section of this main section? (enter 'y' or 'n): "))
            sub_exit_question = sub_exit_question.upper()
            if sub_exit_question == 'Y': #exiting out of the sub_section
                for j in range(len(sub_sections)):
                        course_section_html += f'<li class="topic-list-item"><a href="#" class="list-item-link">{sub_sections[j]}</a></li>'
                        if j == len(sub_sections) - 1:
                            course_section_html += '\n</ul>'
                exit_question = str(input("Is this the last section? (enter 'y' or 'n'): "))#exiting out of the main_section
                exit_question = exit_question.upper()
                if exit_question == 'Y':
                    main_exit = True
                elif exit_question == 'N':
                    main_exit = False
                progress += 1
                progress_string = str(progress)+"th"
                sub_section_exit = True
            elif sub_exit_question == 'N': #Not exiting out of the sub_section
                sub_section_exit = False
    return course_title, course_section_html


def code_converter(course_name, given_html): #Converting both main and sub sections lists into html code.
    main_sub_code = ''
    course_title_code = f'<div class="course-title">\n<h3 class="course-title heading-secondary">{course_name}</h3>\n</div>\n'
    main_sub_code += given_html
    closing_code = '\n</div>\n</div>\n</section>'
    final_code = f'<section>\n{course_title_code}<div class="course-content">\n<div class="course-topic">\n{main_sub_code}\n{closing_code}'
    return final_code


def file_exporter(x):
    file = open('code_file.txt','w')
    file.write(x)

def main():
    course_title, course_section_html = input_function()
    converted_code = code_converter(course_title,course_section_html)
    file_exporter(converted_code)
main()
#All Authored By NISM (David Liu)