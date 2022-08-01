vim.g.mapleader = " "
local key_map = vim.api.nvim_set_keymap
key_map("n", "<leader>ff", [[<Cmd>NvimTreeToggle<CR>]], {noremap=true, silent=true})
key_map("n", "<leader>n", [[<Cmd>NvimTreeFocus<CR>]], {noremap=true, silent=true})
key_map("n", "<leader>fo", [[<Cmd>NvimTreeFindFileToggle<CR>]], {noremap=true, silent=true})
key_map("n", "th", [[<Cmd>BufferLineCycleNext<CR>]], {noremap=false, silent=false})
key_map("n", "tl", [[<Cmd>BufferLineCyclePrev<CR>]], {noremap=false, silent=true})
key_map("n", "ta", [[ggVG<CR>]], {noremap=false, silent=false})
key_map("v", "<leader>y", [[<Cmd>w !pbcopy<CR>]], {noremap=true, silent=true})
key_map("n", "<leader>p", [[<Cmd>r !pbpaste<CR>]], {noremap=true, silent=true})
