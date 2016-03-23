#include "game.h"
#include <QList>
#include <random>
#include <time.h>
#include <QMessageBox>
#include <QIcon>
#include <QPushButton>

Game::Game()
{
    srand(time(0));
    initialize();
}

void Game::initialize()
{
    int widthScene = 500;
    int heightScene = 300;
    int widthBird = widthScene / 10;
    int heightBird = heightScene / 10;
    int xBird = widthScene / 3 - widthBird / 2;
    int yBird = heightScene / 2 - heightBird / 2;

    Bird *bird = new Bird(widthBird, heightBird, viewBackground);
    scene = new MyScene();
    scene->setSceneRect(0, 0, widthScene, heightScene);
    scene->addItem(bird);
    bird->setPos(xBird, yBird);

    view = new MyView(scene);
    view->setGeometry(100, 100, 1000, 600);
    view->setBackgroundBrush(QBrush(viewBackground));

    QObject::connect(scene, SIGNAL(timeIsOver(qreal)), bird, SLOT(updatePos(qreal)));
    QObject::connect(scene, SIGNAL(keyIsPress()), bird, SLOT(keyPress()));
    QObject::connect(bird, SIGNAL(reStartGame()), this, SLOT(reStartGame()));

    view->show();

    timerId = startTimer(timerInterval);
}

void Game::timerEvent(QTimerEvent *)
{
    int h0 = rand() % 200;
    int h1 = 300 - h0 - 100;
    int w = scene->width() / 15;

    Column *c1 = new Column(1, w, h1);
    scene->addItem(c1);
    c1->setPos(scene->sceneRect().bottomRight());
    QObject::connect(scene, SIGNAL(timeIsOver(qreal)), c1, SLOT(updatePos(qreal)));
    QObject::connect(c1, SIGNAL(deleteItem(QGraphicsItem*)), scene, SLOT(deleteItem(QGraphicsItem*)));

    Column *c2 = new Column(0, w, h0);
    scene->addItem(c2);
    c2->setPos(scene->sceneRect().topRight());
    QObject::connect(scene, SIGNAL(timeIsOver(qreal)), c2, SLOT(updatePos(qreal)));
    QObject::connect(c2, SIGNAL(deleteItem(QGraphicsItem*)), scene, SLOT(deleteItem(QGraphicsItem*)));
}

void Game::reStartGame()
{
    this->killTimer(timerId);
    QMessageBox mb;
    QList<QGraphicsItem*> l = scene->items();
    for (auto it = l.begin(); it != l.end(); ++it)
        delete (*it);
    delete scene;
    delete view;
    mb.setText(tr("GAME OVER!"));
    QPushButton *buttonExit = mb.addButton(tr("Exit"), QMessageBox::ActionRole);
    QPushButton *buttonContinue = mb.addButton(tr("Restart"), QMessageBox::ActionRole);
    mb.exec();
    if (mb.clickedButton() == buttonContinue)
    {
        initialize();
    }
}
