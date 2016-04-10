#pragma once

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include "Player.h"
#include <memory>
#include <QStackedWidget>
#include <QtWidgets/QPushButton>

class BoardProfileWidget : public QWidget {
public:
    BoardProfileWidget();
    ~BoardProfileWidget();
    void Refresh() const;
private:
    QLabel *playerNameLabel;
    QLabel *playerPictureLabel;
    QLabel *playerElektroLabel;
    QGridLayout *gridLayout;
};

class BoardResourcePowerPlantWiget : public QWidget {
public:
    BoardResourcePowerPlantWiget();
    ~BoardResourcePowerPlantWiget();
    void SetPowerPlantCard(shared_ptr<PowerPlantCard> powerPlantCard) { this->powerPlantCard = powerPlantCard; }
    void Refresh();
    void SetOpacity(float opacity);
private:
    shared_ptr<PowerPlantCard> powerPlantCard;
    QGridLayout *gridLayout;
    vector<QLabel*> resourceLables;
    void paintEvent(QPaintEvent *e) override;
};

class BoardPlayerPowerPlantsWidget : public QWidget {
public:
    BoardPlayerPowerPlantsWidget();
    ~BoardPlayerPowerPlantsWidget();
    void Refresh();
private:
    vector<BoardResourcePowerPlantWiget*> playerPowerPlantsWidgets;
    QGridLayout *gridLayout;
};

class CounterWidget : public QWidget {
    Q_OBJECT
public:
    CounterWidget();
    ~CounterWidget();
    QLabel *GetNumberLabel() const { return numberLabel; }
    int GetValueAsInt() { return stoi(numberLabel->text().toStdString()); }
    QPushButton *GetPlusBtn() const { return plusBtn; }
    QPushButton *GetMinusBtn() const{ return minusBtn; }
    void SetValue(string text) { numberLabel->setText(text.c_str()); }

private:
    QGridLayout *gridLayout;
    QPushButton *plusBtn, *minusBtn;
    QLabel *numberLabel;
    void paintEvent(QPaintEvent *pe) override;
public slots:
    void increment();
    void decrement();
signals:
    void plusPressed(int);
    void minusPressed(int);
};

class StepOnePanel : public QWidget {
public:
    StepOnePanel();
    ~StepOnePanel();
private:
    QGridLayout *gridLayout;
    QPushButton *okButton;
};

class StepTwoPanel : public QWidget {
public:
    StepTwoPanel();
    ~StepTwoPanel();
    CounterWidget *GetCounterWidget() { return counterWidget; }
    QPushButton *GetOkButton() { return okButton; }
    QPushButton *GetSkipButton() { return skipButton; }
private:
    QGridLayout *gridLayout;
    QPushButton *okButton;
    QPushButton *skipButton;
    CounterWidget *counterWidget;
};

class StepThreePanel : public QWidget {
Q_OBJECT
public:
    StepThreePanel();
    ~StepThreePanel();
    CounterWidget *GetCounterWidget() const { return counterWidget; }
private:
    QGridLayout *gridLayout;
    QPushButton *okButton;
    QPushButton *skipButton;
    CounterWidget *counterWidget;
};

class StepFourPanel : public QWidget {
public:
    StepFourPanel();
    ~StepFourPanel();
private:
    QGridLayout *gridLayout;
    QPushButton *okButton;
    QPushButton *skipButton;
};

class StepFivePanel : public QWidget {
public:
    StepFivePanel();
    ~StepFivePanel();
private:
    QGridLayout *gridLayout;
    QPushButton *okButton;
};

class BoardMessageWidget : public QWidget {
public:
    BoardMessageWidget();
    ~BoardMessageWidget();
    void Refresh() const;
    StepOnePanel *GetStepOnePanel() { return stepOnePanel; }
    StepTwoPanel *GetStepTwoPanel() { return stepTwoPanel; }
    StepThreePanel*GetStepThreePanel() { return stepThreePanel; }
    StepFourPanel *GetStepFourPanel() { return stepFourPanel; }
    StepFivePanel *GetStepFivePanel() { return stepFivePanel; }
private:
    QGridLayout *gridLayout;
    QLabel *questionLabel;
    StepOnePanel *stepOnePanel;
    StepTwoPanel *stepTwoPanel;
    StepThreePanel *stepThreePanel;
    StepFourPanel *stepFourPanel;
    StepFivePanel *stepFivePanel;
    QStackedWidget *stepsWidget;
};

class BoardBottomWidget : public QWidget {
public:
    BoardBottomWidget();
    ~BoardBottomWidget();
    void Refresh() const;
    BoardMessageWidget *GetBoardMessage() { return boardMessageWidget; }
private:
    QGridLayout *gridLayout;
    BoardProfileWidget *boardProfileWidget;
    BoardPlayerPowerPlantsWidget *boardPlayerPowerPlantsWidget;
    BoardMessageWidget *boardMessageWidget;
};

