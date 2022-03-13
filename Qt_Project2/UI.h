#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Qt_Project2.h"
#include <QComboBox>
#include <QPushButton>
#include <QTextEdit>
#include "Controller.h"


class UI : public QMainWindow
{
    Q_OBJECT

public:
    /// main widgets used in the GUI
    Controller ctrl;
    QComboBox* specie_box= new QComboBox;
    QPushButton* save = new QPushButton;
    QTextEdit* id_text = new QTextEdit;
    QTextEdit* name_text = new QTextEdit;
    QTextEdit* remove_id = new QTextEdit;
    QComboBox* fly_box= new QComboBox;
    QTextEdit* displayed = new QTextEdit;
    QTextEdit* displayed_filter = new QTextEdit;
    QComboBox* filter_fly= new QComboBox;
    QComboBox* filter_specie = new QComboBox;
    UI(QWidget *parent = Q_NULLPTR);
    
    /// method containing operations
    void UIComponents();
    
    
   

private:
    Ui::Qt_Project2Class ui;

private slots:
    /// slots used
    void onComboBoxActivated(int i);
    void SaveAndExitButton();
    void inputAddPatient();
    void inputRemovePatient();
    void UndoSlot();
    void RedoSlot();
    void Filter1Slot();
    void Filter2Slot();
    
};
