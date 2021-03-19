#### DISTINCT
the DISTINCT keyword instructs the database to return distinct values.
"SELECT DISTINCT [column_name]" only returns rows with a distinct or unique column value

The DISTINCT keyword must be placed directly in front of the column names

Caution: Can’t Be Partially DISTINCT
The DISTINCT keyword applies to all columns, not just the one it precedes. If you were to specify SELECT DISTINCT [colunm_one], [colunm_two], the combined specified columns produced unique combinations.
