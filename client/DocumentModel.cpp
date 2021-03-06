/*
 * QDigiDoc4
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#include "DocumentModel.h"

#include "FileDialog.h"

#include <QFileInfo>

DocumentModel::DocumentModel(QObject *parent)
: QObject(parent)
{}
DocumentModel::~DocumentModel() = default;

void DocumentModel::addTempFiles(const QStringList &files)
{
	for(const QString &file: files)
	{
		addFile(file);
		addTempReference(file);
	}
}

QStringList DocumentModel::tempFiles() const
{
	QStringList copied;
	int rows = rowCount();
	for(int i = 0; i < rows; ++i)
	{
		QFileInfo f(save(i, FileDialog::tempPath(data(i))));
		if(f.exists())
			copied << f.absoluteFilePath();
	}

	return copied;
}
