def replace_words(input_str):
    replacements = {
        "царь": "батюшка",
        "батюшка": "главный",
        "главный": "int",
        "внедрить": "using",
        "обозвать": "typedef",
        "Русь": "std",
        "молвить": "cout",
        "внемлить": "cin",
        "воздать": "return",
        "пахать": "do",
        "покуда": "while",
        "для": "for",
        "коли": "if",
        "отнюдь": "else",
        "династия": "class",
        "семейство": "struct",
        "перепись": "enum",
        "бить_ящеров": "break",
        "добить_ящеров": "continue",
        "путевой_камень": "switch",
        "путь": "case",
        "базированно": "default",
        "правда": "True",
        "кривда": "False",
        "прыг_скок": "endl",
        "новь": "new",
        "казнь": "delete",
        "туда_не_знаю_куда": "None",
        "НИЧТО": "None",
        "судьба": "random",
        "приказ_княжий": "const",
        "мощь": "pow",
        "получи_басурман": "throw",
        "гнев_Перуна": "exception",
        "читать_летопись": "ifstream",
        "писать_летопись": "ofstream",
        "летопись": "fstream",
        "друже": "friend",
        "окстись": "goto",
        "свет_мой_зеркальце": "template",
        "скажи": "typename",
        "царский": "private",
        "народный": "public",
        "дружинный": "protected",
        "встрой": "inline",
        "кощей": "static",
        "однобокий": "unsigned",
        "пытать_ящера": "try",
        "поймать_ящера": "catch",
        "хутор": "namespace",
        "откупорить": "open",
        "закупорить": "close",
        "суд_Перуна": "auto",
        "аки": "static_cast",
        "очами_стрельнуть": "peek",
        "зачерпнуть": "getline",
        "добрый_молодец": "good",
        "змей_подколодный": "fail",
        "вот_и_сказочке_конец": "eof",
        "вск": "eof",
        "приток_Байкала": "ostream",
        "отток_Байкала": "istream",
        "меняло": "std.swap",
        "отщипнуть": "get",
        "целина": "int",
        "вель_дробь": "double",
        "малый_дробь": "float",
        "буква": "char",
        "много_букав": "std.string",
        "бестолочь": "void",
        "карлик": "short",
        "долговязый": "long",
        "Петр_Первый": "long long",
        "мерило": "size_t",
        "розсуд": "bool"
    }

    for old_word, new_word in replacements.items():
        input_str = input_str.replace(old_word, new_word)

    return input_str

# Чтение из файла
with open("Ипкалькулятор.cpp", "r") as input_file:
    file_contents = input_file.read()

# Замена слов в строке
replaced_contents = replace_words(file_contents)

# Запись замененного содержимого в новый файл
with open("Ипкалькулятор2.cpp", "w") as output_file:
    output_file.write(replaced_contents)

print("Замены успешно выполнены и записаны в файл output.cpp")
