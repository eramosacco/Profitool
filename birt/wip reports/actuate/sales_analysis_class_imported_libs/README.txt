README

Important

To generate a report with full macro functionality, a secondary excel file containing macros must be used as a VBA template.

This VBA template should be named reportName.sod.xls and placed in the same directory as the SOD project file.

For example:

+----------------------------------+
|C:\Users\Me\My Documents          |
|----------------------------------|
|myReport.sod <- (Actuate Project) |
|myReport.sod.xls <- (VBA Template)|
|				   |
|				   |
|				   |
|				   |
|				   |
|				   |
|				   |
|				   |
+----------------------------------+

myReport.sod.xls should contain all of the macros that are needed for the exported report.

When it's time to export the report, run it in Actuate Spreadsheet Designer and go to File->Save View As...
Save the file in the same directory as the .sod file and .sod.xls file:

+----------------------------------+
|C:\Users\Me\My Documents          |
|----------------------------------|
|myReport.sod <- (Actuate Project) |
|myReport.sod.xls <- (VBA Template)|
|myReport.xls <- (exported report) |
|				   |
|				   |
|				   |
|				   |
|				   |
|				   |
|				   |
+----------------------------------+

myReport.xls will inherit all macros from myReport.sod.xls.