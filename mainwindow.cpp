#include "mainwindow.h"
#include <QHBoxLayout>
#include <QGraphicsView>
#include <QtWidgets>
#include "socket.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    button1(new QPushButton),
    button2(new QPushButton),
    scene(new paintScene),
    mainLayout(new QHBoxLayout)
{
    setLayout();
    
}



void MainWindow::handleButton() {
    
   
   
    QPushButton *button = new QPushButton;
    button->setText("123");
    connect(button, SIGNAL (released()), this, SLOT (pushButton()));
    setCentralWidget(button);
    //centralWidget()->setLayout(layout);
};

void MainWindow::pushButton() {
    setLayout();
   // setCentralWidget(this->parent());
    //centralWidget()->setLayout(this->layout());
}

void MainWindow::saveButton() {
   // send();
    QString filename= QFileDialog::getSaveFileName(this, "Save As");
    send(filename);
  //  QGraphicsView* view = new QGraphicsView(scene,this);
  //  QString fileName = "file_name.png";
  //  QPixmap pixMap = view->grab(view->sceneRect().toRect());
   // QImage img = pixMap.toImage();
    
    /*
    QImage image(scene->width(), scene->height(), QImage::Format_RGB32);
    image.fill(NULL);
    QPainter painter(&image);
    scene->render(&painter);
    //image.save("/somepath/result.png");
    
    
    image.save(QFileDialog::getSaveFileName(0,tr("Save image"),QDir::currentPath(),"Image PNG(*.png);; Image BMP (*.bmp);; Jpeg (*.jpg)"));
    */
   // fileName = QFileDialog::getSaveFileName(pixMap.toImage(), "Save file", "", ".png");
    //pixMap.save(fileName);
}

MainWindow::~MainWindow()
{
    delete button1;
    delete button2;
    delete scene;
    delete ui;
   // delete textEdit;
}

void MainWindow::on_pushButtonClose_clicked()
{
   // ui->button->setText("Button is clicked");
}


