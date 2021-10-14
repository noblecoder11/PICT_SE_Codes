#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QColor>   // this was added for color

// class RenderArea is defined here
class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = nullptr);
    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

signals:

private:
    // load shape specific data
    void on_shape_changed();
    // compute fuction calls fuction for each shape depending on mShape
    QPointF compute (float t);
    // individual compute algorithms
    QPointF compute_astroid(float t);
    QPointF compute_cycloid(float t);
    QPointF compute_huygens(float t);
    QPointF compute_hypo(float t);
    QPointF compute_line(float t);

private:
    // m stands for member variables
    QColor mBackgroundColor;
    QColor mShapeColor;
    ShapeType mShape;

    // shape specific values
    int mScale;
    float mIntervalLength;
    int mStepCount;
};

#endif // RENDERAREA_H
