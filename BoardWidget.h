#pragma once

#include <QWidget>
#include <QGridLayout>
#include "BoardTopWidget.h"
#include "BoardBottomWidget.h"
#include "BoardCenterWidget.h"

class BoardWidget : public QWidget {
public:
	BoardWidget();
	~BoardWidget();

private:
	QGridLayout *gridLayout;
	BoardTopWidget *boardTopWidget;
	BoardBottomWidget *boardBottomWidget;
	BoardCenterWidget *boardCenterWidget;
};

