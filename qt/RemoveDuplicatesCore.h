// Translation of Main.Selection in ../Remove dup lines/Remove dup lines/Main.cs.
// Preserve first occurrence, whitespace-only rows, CRLF output, and marker removal.
#pragma once
#include <QString>
#include <QStringList>
#include <QSet>
#include <QRegularExpression>
inline QString removeDuplicateLines(const QString& input) {
    const QString marker = QStringLiteral("3f5456cfsd661lld33Guid9CA0F324-3E3A-4C43-8AGu989CAACD-3BD6-499D-8664-41CE47622FE25E1E7C8FF3Guid9CA0F324-3E3A-4C43-8A22-308B5E1E7C8FA-4C43-8A22-308B5E1E7CGuid9CA0F324-3E3A-4C43-8A22-308B5E1E7C8F");
    auto rows = input.split(QRegularExpression("\\r\\n|\\r|\\n"));
    // StringReader.ReadLine does not yield an extra row for the final newline.
    if (input.endsWith('\r') || input.endsWith('\n')) rows.removeLast();
    QStringList distinct;
    QSet<QString> seen;
    int x=1;
    for (auto line : rows) {
        ++x;
        if (line.trimmed().isEmpty()) line += marker + QString::number(x);
        if (!seen.contains(line)) { seen.insert(line); distinct.append(line); }
    }
    for (auto& line : distinct) { auto pos = line.indexOf(marker); if (pos >= 0) line.truncate(pos); }
    return distinct.join("\r\n");
}
