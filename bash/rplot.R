require('tidyverse')
df <- read_delim('./file.csv',
								 delim=",", show_col_types = FALSE)

# df$count <- factor(df$count,
									 # levels = df$count[order(df$count)])

ggplot(df, aes(x = name, y = count)) +
  geom_bar(aes(fill=name),
					 stat = "identity",
					 width = .5,
					 position="dodge") + 
	ylab("lines") + xlab("languages")
