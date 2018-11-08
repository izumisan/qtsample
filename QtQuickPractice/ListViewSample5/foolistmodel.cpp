#include <Qdebug>
#include "foolistmodel.h"

FooListModel::FooListModel( QObject* parent )
    : QAbstractListModel(parent)
    , m_data()
{
    this->add( Foo( "white", QColor( Qt::white ) ) );
    this->add( Foo( "black", QColor( Qt::black ) ) );
    this->add( Foo( "cyan", QColor( Qt::cyan ) ) );
    this->add( Foo( "darkCyan", QColor( Qt::darkCyan ) ) );
    this->add( Foo( "red", QColor( Qt::red ) ) );
    this->add( Foo( "darkRed", QColor( Qt::darkRed ) ) );
    this->add( Foo( "magenta", QColor( Qt::magenta ) ) );
    this->add( Foo( "darkMagenta", QColor( Qt::darkMagenta ) ) );
    this->add( Foo( "green", QColor( Qt::green ) ) );
    this->add( Foo( "darkGreen", QColor( Qt::darkGreen ) ) );
    this->add( Foo( "yellow", QColor( Qt::yellow ) ) );
    this->add( Foo( "darkYellow", QColor( Qt::darkYellow ) ) );
    this->add( Foo( "blue", QColor( Qt::blue ) ) );
    this->add( Foo( "darkBlue", QColor( Qt::darkBlue ) ) );
    this->add( Foo( "gray", QColor( Qt::gray ) ) );
    this->add( Foo( "darkGray", QColor( Qt::darkGray ) ) );
    this->add( Foo( "lightGray", QColor( Qt::lightGray ) ) );
}

void FooListModel::add( const Foo& foo )
{
    beginInsertRows( QModelIndex(), rowCount(), rowCount() );
    m_data.append( foo );
    endInsertRows();
}

/*!
  @brief  先頭要素を削除する
*/
void FooListModel::removeFirst()
{
    qDebug() << "removeFirst";
    beginRemoveRows( QModelIndex(), 0, 0 );
    m_data.removeFirst();
    endRemoveRows();
}

/*!
  @brief  末尾にデフォルト要素を追加する
*/
void FooListModel::pushBack()
{
    qDebug() << "pushBack";
    beginInsertRows( QModelIndex(), rowCount(), rowCount() );
    m_data.append( Foo() );
    endInsertRows();
}

int FooListModel::rowCount( const QModelIndex& parent ) const
{
    Q_UNUSED(parent);
    return m_data.count();
}

QVariant FooListModel::data( const QModelIndex& index, int role ) const
{
    auto&& ret = QVariant();
    if ( ( 0 <= index.row() ) && ( index.row() < m_data.count() ) )
    {
        auto&& foo = m_data.at( index.row() );
        switch ( static_cast<FooRole>( role ) )
        {
        case FooRole::NameRole:
            ret = QVariant( QString( foo.name().c_str() ) );
            break;
        case FooRole::ColorRole:
            ret = QVariant( foo.color() );
            break;
        case FooRole::CountRole:
            ret = QVariant( m_data.count() );
            break;
        default:
            break;
        }
    }
    return ret;
}

QHash<int, QByteArray> FooListModel::roleNames() const
{
    return QHash<int, QByteArray>
    {
        { static_cast<int>( FooRole::NameRole ), "name" },
        { static_cast<int>( FooRole::ColorRole ), "colorRole" },  // "color"はQMLプロパティ名と被るので上手く動作しない
        { static_cast<int>( FooRole::CountRole ), "count" }
    };
}

