#include <QMainWindow>
#include <QPushButton>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGraphicsView>

#include <QGraphicsSceneResizeEvent>
#include <paintscene.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    
    ~MainWindow();
    
    
    void setLayout()
    {
        QVBoxLayout *layout = new QVBoxLayout;
        
        QTextEdit *txt = new QTextEdit;
        txt = new QTextEdit;
        QGraphicsView *view = new QGraphicsView;
        button1 = new QPushButton;
        button2 = new QPushButton;
        
        button1->setStyleSheet("QPushButton::pressed {background-color: red;} QPushButton {background-color: #fafafa; border-radius: 4px; color: green; max-width: 100px; height: 25px;}");
        
        scene = new paintScene;
       // textEdit = new QTextEdit;
        button1->setText("button1");
        button2->setText("button2");

        txt->setMaximumHeight(50);
        
        //txt->setText("text");
        //txt->resize(200,200);
        //showFullScreen();
        
        scene->setSceneRect(0,0, 570, 320);
        view->setScene(scene);
        view->setMouseTracking(false);
        
        layout->addWidget(view);
        layout->addWidget(txt);
        layout->addWidget(button1);
        layout->addWidget(button2);
        connect(button1, SIGNAL (released()), this, SLOT (handleButton()));
        connect(button2, SIGNAL (released()), this, SLOT (saveButton()));
        connect(txt, SIGNAL (textChanged()), this, SLOT (handleButton()));
        
        setCentralWidget(new QWidget);
        
        centralWidget()->setLayout(layout);
    }

private slots:
    void on_pushButtonClose_clicked();
    void handleButton();
    void pushButton();
    void saveButton();

private:
    //MainWindow *ui;
    QPushButton *button1, *button2;
    MainWindow *ui;

   // QTextEdit *textEdit;
   paintScene *scene;
    QHBoxLayout *mainLayout;
    
};
