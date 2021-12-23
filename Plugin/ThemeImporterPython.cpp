#include "ThemeImporterPython.hpp"

ThemeImporterPython::ThemeImporterPython()
{
    SetKeywords0(
        "and as assert break class continue def del elif else except exec finally for from global if import in "
        "is lambda not or pass print raise return try while with yield True False None pass");
    SetFileExtensions("*.py;waf;wscript;wscript_build");
    m_langName = "python";
}

ThemeImporterPython::~ThemeImporterPython() {}

LexerConf::Ptr_t ThemeImporterPython::Import(const wxFileName& theme_file)
{
    LexerConf::Ptr_t lexer = InitializeImport(theme_file, GetLangName(), wxSTC_LEX_PYTHON);
    AddProperty(lexer, wxSTC_P_DEFAULT, "Default", m_foreground.colour, m_background.colour);
    AddProperty(lexer, wxSTC_P_COMMENTLINE, "Comment", m_singleLineComment.colour, m_background.colour);
    AddProperty(lexer, wxSTC_P_COMMENTLINE, "Number", m_number.colour, m_background.colour);
    AddProperty(lexer, wxSTC_P_STRING, "String", m_string.colour, m_background.colour);
    AddProperty(lexer, wxSTC_P_CHARACTER, "Character", m_string.colour, m_background.colour);
    AddProperty(lexer, wxSTC_P_WORD, "Word", m_keyword.colour, m_background.colour); // keywords
    AddProperty(lexer, wxSTC_P_TRIPLE, "Triple", m_multiLineComment.colour, m_background.colour);
    AddProperty(lexer, wxSTC_P_TRIPLEDOUBLE, "Double Triple", m_multiLineComment.colour, m_background.colour);
    AddProperty(lexer, wxSTC_P_CLASSNAME, "Class Name", m_klass.colour, m_background.colour);
    AddProperty(lexer, wxSTC_P_DEFNAME, "Def Name", m_function.colour, m_background.colour);
    AddProperty(lexer, wxSTC_P_OPERATOR, "Operator", m_oper.colour, m_background.colour);
    AddProperty(lexer, wxSTC_P_IDENTIFIER, "Identifier", m_variable.colour, m_background.colour);
    AddProperty(lexer, wxSTC_P_COMMENTBLOCK, "Comment block", m_multiLineComment.colour, m_background.colour);
    AddProperty(lexer, wxSTC_P_STRINGEOL, "String EOL", m_string.colour, m_background.colour);
    AddProperty(lexer, wxSTC_P_WORD2, "Classes", m_klass.colour, m_background.colour); // local variables
    AddProperty(lexer, wxSTC_P_DECORATOR, "Decorator", m_klass.colour, m_background.colour);
    FinalizeImport(lexer);
    return lexer;
}