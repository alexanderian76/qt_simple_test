#ifndef PAINTSCENE\_H
#define PAINTSCENE\_H
 
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

 
class paintScene : public QGraphicsScene
{
 
    Q_OBJECT
 
public:
    explicit paintScene(QObject *parent = 0);
    ~paintScene();
 
private:
    QPointF     previousPoint;      // Координаты предыдущей точки
 
private:
    // Для рисования используем события мыши
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
 
};
 
#endif // PAINTSCENE\_H