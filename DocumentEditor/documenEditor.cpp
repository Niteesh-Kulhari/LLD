#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

class DocumentElement
{
public:
    virtual string render() = 0;
};

class TextElement : public DocumentElement
{
private:
    string text;

public:
    TextElement(string text)
    {
        this->text = text;
    }

    string render() override
    {
        return text;
    }
};

class ImageElement : public DocumentElement
{
private:
    string path;

public:
    ImageElement(string path)
    {
        this->path = path;
    }

    string render() override
    {
        return path;
    }
};

class NewLineElement : public DocumentElement
{
public:
    string render() override
    {
        return "\n";
    }
};

class TabSpaceElement : public DocumentElement
{
public:
    string render() override
    {
        return "\t";
    }
};

class Document
{
private:
    vector<DocumentElement *> documentElements;

public:
    void addElements(DocumentElement *element)
    {
        documentElements.push_back(element);
    }

    string Render()
    {
        string result;

        for (auto elem : documentElements)
        {
            result += elem->render();
        }

        return result;
    }
};

class Persistence
{
public:
    virtual void save(string data) = 0;
};

class FileStorage : public Persistence
{
public:
    void save(string data) override
    {
        ofstream outFile("document.txt");
        if (outFile)
        {
            outFile << data;
            outFile.close();
            cout << "Document saved to document.txt" << endl;
        }
        else
        {
            cout << "Error: Unable to save document" << endl;
        }
    }
};

class DBStorage : public Persistence
{
public:
    void save(string data) override
    {
        cout << "Saving to DATABASE" << endl;
    }
};

class DocumentEditor
{
private:
    Document *document;
    Persistence *storage;
    string renderDocuments;

public:
    DocumentEditor(Document *document, Persistence *storage)
    {
        this->document = document;
        this->storage = storage;
    }

    void addText(string text)
    {
        document->addElements(new TextElement(text));
    }

    void addImage(string path)
    {
        document->addElements(new ImageElement(path));
    }

    void addNewLine()
    {
        document->addElements(new NewLineElement());
    }

    void addTabSpaces()
    {
        document->addElements(new TabSpaceElement());
    }

    string renderDocument()
    {
        if (renderDocuments.empty())
        {
            renderDocuments = document->Render();
        }

        return renderDocuments;
    }

    void saveDocument()
    {
        storage->save(renderDocument());
    }
};

int main()
{

    Document *document = new Document();
    Persistence *persistance = new FileStorage();

    DocumentEditor *editor = new DocumentEditor(document, persistance);

    editor->addText("Hello World!");
    editor->addNewLine();
    editor->addTabSpaces();
    editor->addText("This is my LLD program");
    editor->addNewLine();

    cout << editor->renderDocument() << endl;
    editor->saveDocument();

    return 0;
}