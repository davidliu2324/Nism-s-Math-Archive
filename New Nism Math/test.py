 while not sub_section_exit:
            sub_section_entry = str(input("Enter a sub-section (in order and one at a time): "))
            sub_sections.append(sub_section_entry)
            sub_exit_question = str(input("Is this the last sub-section of this main section? (enter 'y' or 'n): "))
            sub_exit_question = sub_exit_question.upper()
            while 