#ifndef CONFIRMATION_H
#define CONFIRMATION_H

#include <QObject>
#include <QString>
#include <QVariant>

class Confirmation : public QObject
{
    Q_OBJECT
    Q_PROPERTY( QString title READ title NOTIFY titleChanged )
    Q_PROPERTY( QVariant content READ content WRITE setContent NOTIFY contentChanged )
    Q_PROPERTY( int resultCode READ resultCode WRITE setResultCode NOTIFY resultCodeChanged )
signals:
    void titleChanged() const;
    void contentChanged() const;
    void resultCodeChanged() const;

public:
    explicit Confirmation( QObject* parent = nullptr );
    Confirmation( const QString& title, QObject* parent = nullptr );
    Confirmation( const QString& title, const QVariant& content, QObject* parent = nullptr );
    virtual ~Confirmation() = default;

public:
    QString title() const;
    void setTitle( const QString& value );
    QVariant content() const;
    void setContent( const QVariant& value );
    int resultCode() const;
    void setResultCode( const int& value );

public:
    bool isAccepted() const;
    bool isRejected() const;

private:
    QString m_title = {};
    QVariant m_content = {};
    int m_resultCode = 0;
};

#endif // CONFIRMATION_H
