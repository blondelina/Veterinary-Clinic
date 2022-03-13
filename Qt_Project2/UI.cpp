#include "UI.h"
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include "Controller.h"
#include <QLabel>
#include <QComboBox>
#include <QTextEdit>
#include <QMessageBox>
#include "Bird.h"

UI::UI(QWidget *parent)
    : QMainWindow(parent)
{///GUI constructor
    
    ctrl.load();
    ui.setupUi(this);
    setWindowTitle("Veterinary clinic");
    setFixedSize(500,350);
    UIComponents();

}



void UI::UIComponents()
{

    /// main window
    QWidget* wdg = new QWidget(this);
    QGridLayout* vlay = new QGridLayout(wdg);
    QLabel* l = new QLabel("Welcome!");
    l->setAlignment(Qt::AlignCenter);
    l->setStyleSheet("font: 18pt;");
    


    ///widgets on the main window
    vlay->addWidget(l);
    QPushButton* btn1 = new QPushButton("New Patient");
    vlay->addWidget(btn1);
    QPushButton* btn2 = new QPushButton("Display patients");
    vlay->addWidget(btn2);
    QPushButton* btn6 = new QPushButton("Remove patient");
    vlay->addWidget(btn6);
    QPushButton* btn3 = new QPushButton("Filter");
    vlay->addWidget(btn3);
    QPushButton* btn4 = new QPushButton("Undo");
    vlay->addWidget(btn4);
    QPushButton* btn5 = new QPushButton("Redo");
    vlay->addWidget(btn5);
    save->setText("Save and Exit");
    vlay->addWidget(save);
    wdg->setLayout(vlay);
    setCentralWidget(wdg);



    ///add patient operation
    QWidget* wdg1 = new QWidget;
    wdg1->setWindowTitle("New Patient");
    wdg1->setFixedSize(300,200);
    QGridLayout* vlay1 = new QGridLayout(wdg1);
    
    QLabel* l2 = new QLabel("id:");
    vlay1->addWidget(l2);
    id_text->setFixedHeight(25);
    id_text->setFixedWidth(100);
    vlay1->addWidget(id_text);

    QLabel* l1 = new QLabel("name:");
    vlay1->addWidget(l1);
    name_text->setFixedHeight(25);
    name_text->setFixedWidth(100);
    vlay1->addWidget(name_text);

    specie_box->addItem("Cat");
    specie_box->addItem("Bird");
    specie_box->addItem("Dog");
    specie_box->setCurrentIndex(1);
    vlay1->addWidget(specie_box);
    
    fly_box->addItem("Can fly");
    fly_box->addItem("Cannot fly");
    vlay1->addWidget(fly_box);

    QPushButton* new_btn1 = new QPushButton("Add");
    vlay1->addWidget(new_btn1);
    wdg1->setLayout(vlay1);
    
    connect(btn1, SIGNAL(clicked()), wdg1, SLOT(show()));
    connect(specie_box, SIGNAL(activated(int)), this, SLOT(onComboBoxActivated(int)));
    connect(new_btn1, SIGNAL(clicked()), this, SLOT(inputAddPatient()));



    ///display operation
    QWidget* wdg3 = new QWidget();
    wdg3->setWindowTitle("Patients");
    wdg3->setFixedSize(350, 250);
    QGridLayout* vlay3 = new QGridLayout(wdg3);
    wdg3->setLayout(vlay3);
    displayed->setFixedSize(300, 200);
    displayed->setReadOnly(true);
    displayed->setText(ctrl.displayed_repo());
    vlay3->addWidget(displayed);
    connect(btn2, SIGNAL(clicked()), wdg3, SLOT(show()));
    


    ///undo operation
    connect(btn4, SIGNAL(clicked()), this, SLOT(UndoSlot()));



    ///redo operation
    connect(btn5, SIGNAL(clicked()), this, SLOT(RedoSlot()));
    


    ///save and load
    connect(save, SIGNAL(clicked()), this, SLOT(SaveAndExitButton()));
    
    

    ///remove operation
    QWidget* wdg2 = new QWidget;
    wdg2->setWindowTitle("Remove patient");
    wdg2->setFixedSize(300, 100);
    QGridLayout* vlay2 = new QGridLayout(wdg2);
    QLabel* l3 = new QLabel("id:");
    vlay2->addWidget(l3);
    
    remove_id->setFixedHeight(25);
    remove_id->setFixedWidth(100);
    vlay2->addWidget(remove_id);
    
    QPushButton* new_btn2 = new QPushButton("Remove");
    vlay2->addWidget(new_btn2);

    connect(btn6, SIGNAL(clicked()), wdg2, SLOT(show()));
    connect(new_btn2, SIGNAL(clicked()), this, SLOT(inputRemovePatient()));
    


    ///filter
    QWidget* wdg4 = new QWidget();
    wdg4->setWindowTitle("Filter");
    wdg4->setFixedSize(350, 300);
    QGridLayout* vlay4 = new QGridLayout(wdg4);
    wdg4->setLayout(vlay4);
    QPushButton* button1 = new QPushButton("Filter by fly ability");
    vlay4->addWidget(button1);
    QPushButton* button2 = new QPushButton("Filter by specie");
    vlay4->addWidget(button2);
    
    QWidget* wdg5 = new QWidget();
    QGridLayout* vlay5 = new QGridLayout(wdg5);
    
    filter_fly->addItem("Can fly");
    filter_fly->addItem("Cannot fly");
    vlay5->addWidget(filter_fly);
    QPushButton* button3 = new QPushButton("Confirm");
    vlay5->addWidget(button3);
    connect(button1, SIGNAL(clicked()), wdg5, SLOT(show()));

    QWidget* wdg6 = new QWidget();
    QGridLayout* vlay6 = new QGridLayout(wdg6);
    
    filter_specie->addItem("Cat");
    filter_specie->addItem("Bird");
    filter_specie->addItem("Dog");
    vlay6->addWidget(filter_specie);
    QPushButton* button4 = new QPushButton("Confirm");
    vlay6->addWidget(button4);
    connect(button2, SIGNAL(clicked()), wdg6, SLOT(show()));
    
    displayed_filter->setFixedSize(300, 200);
    displayed_filter->setReadOnly(true);
    vlay4->addWidget(displayed_filter);
    connect(btn3, SIGNAL(clicked()), wdg4, SLOT(show()));
    connect(button3, SIGNAL(clicked()), this, SLOT(Filter1Slot()));
    connect(button4, SIGNAL(clicked()), this, SLOT(Filter2Slot()));

}



/// custom slots used

void UI::onComboBoxActivated(int i)
{
    if (i == 1)
        fly_box->setDisabled(false);
    else
        fly_box->setDisabled(true);
}


void UI::inputAddPatient()
{
    

    QString id_str = id_text->toPlainText();
    QString name_str = name_text->toPlainText();
    int id = id_str.toInt();
    string name = name_str.toStdString();


    int specie = specie_box->currentIndex();
    specie++;
    Patient *p = new Patient(id, name, specie);
    if(name!="")
    try{
    if (specie == 2)
    {
        int fly = fly_box->currentIndex();
        
        if (fly == 0)
        {
            Bird* b = new Bird(id, name, specie, false);
            Patient *p = b;
            ctrl.addPatient(p);
        }
        else
        {
            Bird* b = new Bird(id, name, specie, true);
            Patient* p = b;
            ctrl.addPatient(p);
        }
        

    }
    else
    {
        
        ctrl.addPatient(p);
    }
        QMessageBox* q = new QMessageBox;
        q->setWindowTitle("Message");
        q->setText("Patient added successfully");
        q->show();
        displayed->setText(ctrl.displayed_repo());
    }
    
     catch (exception)
     {
            QMessageBox* q = new QMessageBox;
            q->setIcon(QMessageBox::Critical);
            q->setWindowTitle("Warning");
            q->setText("Cannot add patients with the same id");
            q->show();
      }
    
    else
    {
        QMessageBox* q = new QMessageBox;
        q->setIcon(QMessageBox::Critical);
        q->setWindowTitle("Warning");
        q->setText("Nothing to add");
        q->show();
    }

}

void UI::inputRemovePatient()
{
    QString id_str=remove_id->toPlainText();
    int id = id_str.toInt();
    try {
        ctrl.deletePatient(id);
        displayed->setText(ctrl.displayed_repo());
        QMessageBox* q = new QMessageBox;
        q->setWindowTitle("Message");
        q->setText("Patient removed successfully");
        q->show();
    }
    catch (exception)
    {
        QMessageBox* q = new QMessageBox;
        q->setIcon(QMessageBox::Critical);
        q->setWindowTitle("Warning");
        q->setText("Nothing to remove");
        q->show();
    }
    

}


void UI::UndoSlot()
{
    try
    {
        ctrl.undo();
        displayed->setText(ctrl.displayed_repo());
        QMessageBox* q = new QMessageBox;
        q->setWindowTitle("Message");
        q->setText("Undo done successfully");
        q->show();
    }
    catch (exception)
    {
        QMessageBox* q = new QMessageBox;
        q->setIcon(QMessageBox::Critical);
        q->setWindowTitle("Warning");
        q->setText("Nothing to undo");
        q->show();
    }
}

void UI::RedoSlot()
{
    try
    {
        ctrl.redo();
        displayed->setText(ctrl.displayed_repo());
        QMessageBox* q = new QMessageBox;
        q->setWindowTitle("Message");
        q->setText("Redo done successfully");
        q->show();
    }
    catch (exception)
    {
        QMessageBox* q = new QMessageBox;
        q->setIcon(QMessageBox::Critical);
        q->setWindowTitle("Warning");
        q->setText("Nothing to redo");
        q->show();
    }
}

void UI::Filter1Slot()
{
    if(filter_fly->currentIndex() == 0)
        displayed_filter->setText(ctrl.filter_birds(1));
    else 
        displayed_filter->setText(ctrl.filter_birds(2));
    
}

void UI::Filter2Slot()
{
    if (filter_specie->currentIndex() == 0)
        displayed_filter->setText(ctrl.filter_by_specie(1));
    else if(filter_specie->currentIndex() == 1)
        displayed_filter->setText(ctrl.filter_by_specie(2));
    else
        displayed_filter->setText(ctrl.filter_by_specie(3));

}



void UI::SaveAndExitButton()
{
    ctrl.save();
    QApplication::quit();
}






