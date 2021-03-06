#include "BoardCenterWidget.h"
#include "Game.h"
#include <QtWidgets/QStyleOption>

BoardCenterWidget::BoardCenterWidget() {
    
    // Init components
    gridLayout = new QGridLayout();
    centerStackedWidget = new QStackedWidget();
    modeWidget = new QWidget();
    vBoxLayout = new QVBoxLayout();
    powerPlantsModeButton = new QPushButton();
    mapModeButton = new QPushButton();
    resourceMarketModeButton = new QPushButton();
    overviewModeButton = new QPushButton();
    powerPlantModeWidget = new PowerPlantModeWidget();
    resourceMarketModeWidget = new ResourceMarketModeWidget();
    overviewModeWidget = new OverviewModeWidget();
    mapModeWidget = new MapModeWidget();

    // Configure components
    modeWidget->setObjectName("modeWidget");
    powerPlantsModeButton->setObjectName("boardModeButton");
    mapModeButton->setObjectName("boardModeButton");
    resourceMarketModeButton->setObjectName("boardModeButton");
    overviewModeButton->setObjectName("boardModeButton");

    // Set icons
    mapModeButton->setIcon(QIcon(":/PowerGrid/Resources/buttons/map_mode.png"));
    powerPlantsModeButton->setIcon(QIcon(":/PowerGrid/Resources/buttons/power_mode.png"));
    resourceMarketModeButton->setIcon(QIcon(":/PowerGrid/Resources/buttons/resource_mode.png"));
    overviewModeButton->setIcon(QIcon(":/PowerGrid/Resources/buttons/overview_mode.png"));

    // Set layout
    setLayout(gridLayout);
    modeWidget->setLayout(vBoxLayout);

    // Add to stack
    powerPlantModeWidgetIndex = centerStackedWidget->addWidget(powerPlantModeWidget);
    resourceMarketModeWidgetIndex = centerStackedWidget->addWidget(resourceMarketModeWidget);
    overviewModeWidgetIndex = centerStackedWidget->addWidget(overviewModeWidget);
    mapModeWidgetIndex = centerStackedWidget->addWidget(mapModeWidget);

    // Default active
    centerStackedWidget->setCurrentIndex(mapModeWidgetIndex);

    // Connect buttons
    connect(powerPlantsModeButton, SIGNAL(clicked()), this, SLOT(onPowerPlantMode()));
    connect(resourceMarketModeButton, SIGNAL(clicked()), this, SLOT(onResourceMarketMode()));
    connect(overviewModeButton, SIGNAL(clicked()), this, SLOT(onOverviewMode()));
    connect(mapModeButton, SIGNAL(clicked()), this, SLOT(onMapMode()));
        
    // Add components
    vBoxLayout->addWidget(mapModeButton, 0);
    vBoxLayout->addWidget(powerPlantsModeButton, 0);
    vBoxLayout->addWidget(resourceMarketModeButton, 0);
    vBoxLayout->addWidget(overviewModeButton, 0);
    gridLayout->addWidget(centerStackedWidget, 0, 0);
    gridLayout->addWidget(modeWidget, 0, 1, Qt::AlignRight);
}

BoardCenterWidget::~BoardCenterWidget() {
    delete powerPlantsModeButton;
    delete mapModeButton;
    delete resourceMarketModeButton;
    delete overviewModeButton;
    delete powerPlantModeWidget;
    delete mapModeWidget;
    delete resourceMarketModeWidget;
    delete overviewModeWidget;
    delete vBoxLayout;
    delete modeWidget;
    delete centerStackedWidget;
    delete gridLayout;
}

void BoardCenterWidget::Refresh() const
{
    mapModeWidget->Refresh();
    powerPlantModeWidget->Refresh();
    resourceMarketModeWidget->Refresh();
    DrawMap();

    switch (Game::getInstance().GetStep()) {
    case 1:
        centerStackedWidget->setCurrentWidget(mapModeWidget);
        break;
    case 2:
        centerStackedWidget->setCurrentWidget(powerPlantModeWidget);
        break;
    case 3:
        centerStackedWidget->setCurrentWidget(resourceMarketModeWidget);
        break;
    case 4:
        centerStackedWidget->setCurrentWidget(mapModeWidget);
        break;
    case 5:
        centerStackedWidget->setCurrentWidget(overviewModeWidget);
        break;
    default:
        break;
    }
}

void BoardCenterWidget::DrawMap() const
{
    mapModeWidget->DrawMap();
}

/**********
 * SLOTS
 **********/

void BoardCenterWidget::onMapMode() const
{
    qDebug("Switching to map mode");
    centerStackedWidget->setCurrentIndex(mapModeWidgetIndex);
}

void BoardCenterWidget::onResourceMarketMode() const
{
    qDebug("Switching to resource market mode");
    centerStackedWidget->setCurrentIndex(resourceMarketModeWidgetIndex);
}

void BoardCenterWidget::onPowerPlantMode() const
{
    qDebug("Switching to power plant mode");
    centerStackedWidget->setCurrentIndex(powerPlantModeWidgetIndex);
}

void BoardCenterWidget::onOverviewMode() const
{
    qDebug("Switching to overview mode");
    centerStackedWidget->setCurrentIndex(overviewModeWidgetIndex);
}

/// This method is required when Q_OBJECT is added
/// Without this method, the CSS will not be applied
void BoardCenterWidget::paintEvent(QPaintEvent *pe) {
    QStyleOption o;
    o.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &o, &p, this);
};