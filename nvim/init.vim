set termguicolors
lua require 'init'
source $HOME/.config/nvim/vim-plug/plugins.vim
filetype plugin indent on
syntax enable
set t_Co=256
set relativenumber
"colorscheme PaperColor
colorscheme nord 
let g:vimtex_view_method = 'skim'
let g:vimtex_view_skim_sync = 1
let g:vimtex_view_skim_activate = 1
let g:vimtex_view_general_options = '----unique file:@pdf\#src:@line@tex'
let g:vimtex_compiler_latexmk = {
    \ 'options' : [
    \   '-pdf',
    \   '-pdflatex="xelatex --shell-escape %O %S"',
    \   '-verbose',
    \   '-file-line-error',
    \   '-synctex=1',
    \   '-interaction=nonstopmode',
    \ ]
    \}
let g:vimtex_quickfix_autoclose_after_keystrokes = 1
"let g:vimtex_quickfix_enabled = 0
set termguicolors
set number hidden
filetype on
set showtabline=2
set noshowmode

source $HOME/.config/nvim/vim-plug/cp.vim
